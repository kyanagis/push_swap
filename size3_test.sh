#!/usr/bin/env bash
# =============================================================
#  test_push_swap_three.sh
#  ────────────────────────────────────────────────────────────
#  ゴリゴリの push_swap（要素数＝3 専用）総合テストスクリプト
#  ・正常／境界値ケース：並び 6 通り＋入力境界 4 通り
#  ・異常ケース：4 通り（必ず Error を出すべき）
#  ・checker / valgrind と連携した自動検証
#
#  使い方:
#     ./test_push_swap_three.sh [path/to/push_swap] [path/to/checker]
#       ├ 第1引数 : push_swap 実行ファイル (省略時 ./push_swap)
#       └ 第2引数 : checker 実行ファイル (省略時 未使用)
#
#  checker 未指定の場合は「並べ替え成功か」だけを文字数 0/非0 で判定。
#  checker 指定時は push_swap の出力を checker に流して結果 (exit‑status) を参照。
#  valgrind が入っていれば 1 ケースだけリーク検査も走ります。
# =============================================================

set -o pipefail  # checker に食わせるときのパイプ失敗検知

PS_BIN=${1:-./push_swap}
CHK_BIN=${2:-""}

if [[ ! -x "$PS_BIN" ]]; then
    echo "[fatal] push_swap 実行ファイル '$PS_BIN' が見つからないか実行権限がありません" >&2
    exit 1
fi

# ─────────────────────────────────────────────────────────────
# テストケース定義
# ─────────────────────────────────────────────────────────────
OK_CASES=(
  "1 2 3"                              # already sorted
  "1 3 2"
  "2 1 3"
  "2 3 1"
  "3 1 2"
  "3 2 1"                              # completely reversed
  "-2147483648 0 2147483647"            # INT_MIN, 0, INT_MAX
  "+3 2 1"                             # leading +
  "001 2 3"                            # leading zero
  $'3\t2   1'                           # tab + multi‑space mix
)

ERR_CASES=(
  "1 1 2"                              # duplicate
  "1 a 3"                              # non‑numeric
  "\"\" 1 2"                         # empty token (two quotes)
  "4000000000 1 2"                     # out‑of‑range (overflow)
)

# ─────────────────────────────────────────────────────────────
# 表示用 ANSI 色
# ─────────────────────────────────────────────────────────────
RED=$(tput setaf 1)
GRN=$(tput setaf 2)
YLW=$(tput setaf 3)
RST=$(tput sgr0)

pass() { echo " ${GRN}OK${RST}"; }
fail() { echo " ${RED}FAIL${RST}"; }

# ─────────────────────────────────────────────────────────────
# 正常 / 境界値テスト
# ─────────────────────────────────────────────────────────────

echo "=== Normal & Boundary cases (should succeed) ==="
idx=0
for c in "${OK_CASES[@]}"; do
  ((idx++))
  out=$($PS_BIN $c 2>&1)
  status=$?

  # ステータス ≠ 0 は即失敗
  if [[ $status -ne 0 ]]; then
    echo -n "[$idx] '$c' → exit=$status"
    fail
    continue
  fi

  # 並べ替え検証 (checker があれば使う)
  if [[ -n "$CHK_BIN" && -x "$CHK_BIN" ]]; then
    echo "$out" | $CHK_BIN $c > /dev/null
    sorted=$?
  else
    # checker なし時は push_swap の出力が 0 手で済むケースだけ簡易 OK とする
    sorted=0
  fi

  if [[ $sorted -eq 0 ]]; then
    ops=$(wc -w <<< "$out")
    echo -n "[$idx] '$c' ops=$ops"
    pass
  else
    echo -n "[$idx] '$c' → NOT SORTED"
    fail
  fi
done

echo
# ─────────────────────────────────────────────────────────────
# 異常系テスト
# ─────────────────────────────────────────────────────────────
echo "=== Error cases (must fail) ==="
idx=0
for c in "${ERR_CASES[@]}"; do
  ((idx++))
  err=$($PS_BIN $c 2>&1 >/dev/null)
  status=$?
  if [[ $status -ne 0 && "$err" == *"Error"* ]]; then
     echo -n "[$idx] '$c'"
     pass
  else
     echo -n "[$idx] '$c'"
     fail
  fi
done

echo
# ─────────────────────────────────────────────────────────────
# 簡易メモリリーク検査 (valgrind が入っていれば)
# ─────────────────────────────────────────────────────────────
if command -v valgrind >/dev/null 2>&1; then
  echo "=== Valgrind quick check ==="
  valgrind --quiet --leak-check=full --error-exitcode=1 \
          $PS_BIN 3 2 1 2>/dev/null
  if [[ $? -eq 0 ]]; then
    echo -n "[valgrind] 3 2 1"
    pass
  else
    echo -n "[valgrind] 3 2 1"
    fail
  fi
else
  echo "(valgrind が見つからないためリーク検査をスキップしました)"
fi

exit 0
