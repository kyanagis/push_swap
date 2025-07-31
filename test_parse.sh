#!/usr/bin/env bash
BIN=./push_swap

tests=(
 '""'                         # 01 ✗
 '"  "'                       # 02 ✗
 '"1"'                        # 03 ✓
 '"   1   2 3 "'              # 04 ✓
 $'\''4\t5\t6'\'''            # 05 ✓
 $'\''7\n8 9'\'''             # 06 ✓
 '+10 -11 012'                # 07 ✓
 '2147483647 -2147483648'     # 08 ✓
 '"3 2" 1'                    # 09 ✓
 '0 -0'                       # 10 ✗
 '1 2 1'                      # 11 ✗
 '"0001 1"'                   # 12 ✗
 '2147483648'                 # 13 ✗
 '-2147483649'                # 14 ✗
 '12a'                        # 15 ✗
 '+'                          # 16 ✗
 '1--2'                       # 17 ✗
 $'\''\v1 2'\'''              # 18 ✗
 $'\''\f1\t2'\'''             # 19 ✗
 $'\''\r1 2'\'''              # 20 ✗
 $'\''\t\t'\''' '3'           # 21 ✗
 $'\''\n'\'''                 # 22 ✗
 '"42  "' '" \t"'             # 23 ✗
 ''                          
)

expect=(✗ ✗ ✓ ✓ ✓ ✓ ✓ ✓ ✓ ✗ ✗ ✗ ✗ ✗ ✗ ✗ ✗ ✗ ✗ ✗ ✗ ✗ ✗ ✗)

printf "\n\033[1mPush_swap — parse tests\033[0m\n"
idx=0; pass=0
for cmd in "${tests[@]}"; do
  eval $BIN $cmd >/dev/null 2>err
  status=$?
  ok=$([[ ${expect[idx]} == ✓ && $status -eq 0 ]] || \
        [[ ${expect[idx]} == ✗ && $status -ne 0 ]])
  printf "%02d %-40s %b\n" $((idx+1)) "$cmd" \
         "$( $ok && { pass=$((pass+1)); echo '✅'; } || echo '❌' )"
  idx=$((idx+1))
done

echo -e "\n$pass / ${#tests[@]} passed"
rm -f err
