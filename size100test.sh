#!/usr/bin/env bash
# test_100.sh — strict tester for push_swap (N=100)
# Usage:
#   bash test_100.sh [-n RUNS] [-l LIMIT] [--ps ./push_swap] [--checker PATH] [--timeout SECS]
# Examples:
#   bash test_100.sh
#   bash test_100.sh -n 500 -l 680 --ps ./push_swap --checker ./checker_OS --timeout 2

set -Eeuo pipefail

# ===== Default settings =====
N=100
RUNS=200
LIMIT=700         # 100個は <700 手が満点の目安（Subject準拠）
TIMEOUT_S=2
PUSH_SWAP=${PUSH_SWAP:-./push_swap}
CHECKER=${CHECKER:-}

# ===== Colors =====
RED=$'\033[31m'; GREEN=$'\033[32m'; YEL=$'\033[33m'; CYAN=$'\033[36m'; BOLD=$'\033[1m'; NC=$'\033[0m'

# ===== Args =====
while [[ $# -gt 0 ]]; do
  case "$1" in
    -n|--runs) RUNS="$2"; shift 2;;
    -l|--limit) LIMIT="$2"; shift 2;;
    --ps|--push_swap) PUSH_SWAP="$2"; shift 2;;
    --checker) CHECKER="$2"; shift 2;;
    --timeout) TIMEOUT_S="$2"; shift 2;;
    -h|--help)
      echo "Usage: $0 [-n RUNS] [-l LIMIT] [--ps PATH] [--checker PATH] [--timeout SECS]"
      exit 0;;
    *) echo "Unknown arg: $1" >&2; exit 2;;
  esac
done

# ===== Binaries check =====
if [[ ! -x "$PUSH_SWAP" ]]; then
  echo "${RED}push_swap not found or not executable: $PUSH_SWAP${NC}" >&2
  exit 1
fi

find_checker() {
  if [[ -n "${CHECKER:-}" && -x "$CHECKER" ]]; then return; fi
  for c in checker_OS checker_linux checker_Mac checker; do
    if command -v "$c" >/dev/null 2>&1; then CHECKER="$(command -v "$c")"; return; fi
    if [[ -x "./$c" ]]; then CHECKER="./$c"; return; fi
  done
  echo "${RED}checker not found (tried: checker_OS/checker_linux/checker_Mac/checker)${NC}" >&2
  exit 1
}
find_checker

# Optional timeout
TIMEOUT_CMD=""
if command -v timeout >/dev/null 2>&1; then
  TIMEOUT_CMD=(timeout "${TIMEOUT_S}")
elif command -v gtimeout >/dev/null 2>&1; then
  TIMEOUT_CMD=(gtimeout "${TIMEOUT_S}")
else
  TIMEOUT_CMD=()
  echo "${YEL}warning:${NC} timeout command not found. Infinite loop detection is disabled."
fi

# ===== Random unique generator (prefers shuf, falls back to jot) =====
gen_random_args() {
  local n="$1"
  local upper=$(( n * 200 ))   # 十分広い正のレンジ（INT余裕）
  if command -v shuf >/dev/null 2>&1; then
    # 1..upper から重複なしで n 個 → 一部に符号を付ける
    seq 1 "$upper" | shuf -n "$n" | awk 'BEGIN{srand()} { 
      if (rand() < 0.5) printf "-%s ", $1; else printf "%s ", $1
    }'
  elif command -v jot >/dev/null 2>&1; then
    # mac系フォールバック（重複なしサンプル）
    jot -r "$upper" 1 "$upper" | awk '!seen[$0]++' | head -n "$n" | awk 'BEGIN{srand()} {
      if (rand() < 0.5) printf "-%s ", $1; else printf "%s ", $1
    }'
  else
    echo "Neither shuf nor jot available to generate random inputs" >&2
    exit 1
  fi
}

# ===== Helpers =====
COUNTS=()
fail_now() { echo "${RED}${BOLD}FAIL:${NC} $*"; exit 1; }

run_case() {
  local name="$1"; shift
  local args=("$@")
  local out status ops cnt

  # run push_swap (with timeout if available)
  if ! out="$("${TIMEOUT_CMD[@]}" "$PUSH_SWAP" "${args[@]}" 2>ps_err)"; then
    # Segfault / timeout / nonzero exit
    if [[ -s ps_err ]]; then cat ps_err >&2; fi
    rm -f ps_err
    fail_now "push_swap crashed/timeout on ${name}"
  fi
  rm -f ps_err

  # Count ops
  if [[ -z "$out" ]]; then
    cnt=0
  else
    cnt="$(wc -l <<<"$out" | tr -d ' ')"
  fi

  # Verify with checker
  if ! status="$(printf "%s\n" "$out" | "$CHECKER" "${args[@]}")"; then
    fail_now "checker execution failed on ${name}"
  fi
  if [[ "$status" != "OK" ]]; then
    echo "$out" > _last_ops.txt
    fail_now "checker says ${status} on ${name}. Operations saved to _last_ops.txt"
  fi

  # record & print
  COUNTS+=("$cnt")
  local mark="${GREEN}PASS${NC}"
  if [[ "$cnt" -gt "$LIMIT" ]]; then
    mark="${RED}OVER${NC}"
  fi
  printf "%-18s : %5d ops  [%b]\n" "$name" "$cnt" "$mark"

  # hard stop if limit exceeded (strict)
  if [[ "$cnt" -gt "$LIMIT" ]]; then
    echo "${RED}${BOLD}Exceeded limit (${LIMIT}) on ${name}. Strict mode stops here.${NC}"
    exit 1
  fi
}

stats() {
  local n="${#COUNTS[@]}"
  [[ "$n" -gt 0 ]] || return 0
  # sort
  IFS=$'\n' read -r -d '' -a SORTED < <(printf "%s\n" "${COUNTS[@]}" | sort -n && printf '\0')
  local min="${SORTED[0]}"
  local max="${SORTED[$((n-1))]}"
  local sum avg
  sum="$(printf "%s\n" "${COUNTS[@]}" | awk '{s+=$1} END{print s+0}')"
  avg="$(awk -v s="$sum" -v n="$n" 'BEGIN{printf "%.2f", s/n}')"
  local p50="${SORTED[$(( (n-1)*50/100 ))]}"
  local p95="${SORTED[$(( (n-1)*95/100 ))]}"
  local p99="${SORTED[$(( (n-1)*99/100 ))]}"
  echo
  echo "${BOLD}Summary (random ${RUNS} runs)${NC}"
  echo "min=${min}, max=${max}, avg=${avg}, median=${p50}, p95=${p95}, p99=${p99}"
}

# ===== Adversarial inputs (deterministic) =====
make_desc() { seq "$N" -1 1 | tr '\n' ' '; }
make_rot30() { (seq 31 100; seq 1 30) | tr '\n' ' '; }
make_alt() { # 1,100,2,99,3,98,...
  awk -v n="$N" 'BEGIN{for(i=1;i<=n/2;i++){printf "%d %d ", i, (n+1 - i);} if(n%2){printf "%d ", (int((n+1)/2));}}'
}
make_almost() { # nearly sorted: swap 5 disjoint pairs
  seq 1 "$N" | awk 'BEGIN{srand(42)} {a[NR]=$1} END{
    for(i=1;i<=5;i++){x=int(rand()*N)+1; y=int(rand()*N)+1; t=a[x]; a[x]=a[y]; a[y]=t}
    for(i=1;i<=N;i++) printf "%d ", a[i];
  }' N="$N"
}

# ===== Run tests =====
echo "${CYAN}${BOLD}push_swap strict test for N=${N}${NC}"
echo "Binary: $PUSH_SWAP"
echo "Checker: $CHECKER"
echo "Runs: $RUNS  | Limit: $LIMIT  | Timeout: ${TIMEOUT_S}s (if available)"
echo

# Adversarial first
run_case "desc(100..1)" $(make_desc)
run_case "rot(+30)"     $(make_rot30)
run_case "alternating"  $(make_alt)
run_case "almost-sorted" $(make_almost)

# Random battery
for ((i=1;i<=RUNS;i++)); do
  ARG="$(gen_random_args "$N")"
  # shellcheck disable=SC2206
  ARGV=($ARG)
  run_case "random#$i" "${ARGV[@]}"
done

stats

# Error-handling probes (not part of stats)
echo
echo "${BOLD}Error handling probes (expect Error / non-zero)${NC}"
set +e
"${TIMEOUT_CMD[@]}" "$PUSH_SWAP"  # no args → 何も出さない＆0終了が理想（Subject推奨）
ec=$?; echo "no-args exit=$ec"
"${TIMEOUT_CMD[@]}" "$PUSH_SWAP" 1 2 2 3 2>/dev/null; rc=$?; echo "dup -> exit=$rc (expect non-zero)"
"${TIMEOUT_CMD[@]}" "$PUSH_SWAP" 0 one 2 3 2>/dev/null; rc=$?; echo "non-int -> exit=$rc (expect non-zero)"
set -e

echo
echo "${GREEN}${BOLD}All tests done.${NC}"
