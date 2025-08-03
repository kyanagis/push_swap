#!/usr/bin/env bash
set -euo pipefail

PS_BIN=./push_swap
CK_BIN=./checker_linux
PY=python3
RED='\033[0;31m'; GREEN='\033[0;32m'; NC='\033[0m'
fail=0

# ───── 先に置く ─────
gen_perm () {  # $1 = N
    "$PY" - "$1" <<'PY'
import itertools, sys
n = int(sys.argv[1])
for p in itertools.permutations(range(1, n + 1)):
    print(" ".join(map(str, p)))
PY
}

run_case () {
    local bound=$1; shift
    local args=("$@")

    local ops
    if ! ops="$("$PS_BIN" "${args[@]}")"; then
        printf "${RED}CRASH${NC} %s\n" "${args[*]}"; fail=1; return
    fi
    local cnt
    cnt=$( [ -z "$ops" ] && echo 0 || printf '%s\n' "$ops" | wc -l | tr -d ' ' )

    # 正しさ判定（空出力なら /dev/null を渡す）
    if ! { [ -z "$ops" ] \
           && "$CK_BIN" "${args[@]}" < /dev/null \
           || printf '%s\n' "$ops" | "$CK_BIN" "${args[@]}"; } \
         | grep -q '^OK$'; then
        printf "${RED}KO${NC}  (%3s ops) %s\n" "$cnt" "${args[*]}"
        fail=1; return
    fi

    # 手数チェック
    if [ "$cnt" -le "$bound" ]; then
        printf "${GREEN}PASS${NC} (%3s ops) %s\n" "$cnt" "${args[*]}"
    else
        printf "${RED}FAIL${NC} (%3s>%s) %s\n" "$cnt" "$bound" "${args[*]}"
        fail=1
    fi
}
  # 既存のまま
# ──────────────────

echo "=== N = 3 ==="
while read -r line; do run_case 2 $line; done < <(gen_perm 3)

echo "=== N = 4 ==="
while read -r line; do run_case 5 $line; done < <(gen_perm 4)

echo "=== N = 5 ==="
while read -r line; do run_case 8 $line; done < <(gen_perm 5)

if [ "$fail" -eq 0 ]; then
    echo -e "${GREEN}All 150 cases cleared within optimal bounds!${NC}"
else
    echo -e "${RED}Some cases failed.${NC}"
    exit 1
fi
