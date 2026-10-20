#!/usr/bin/env bash
# Usage: ./new_solution.sh 3 longest-substring-without-repeating-characters   -> leetcode/0003-....cpp
#        ./new_solution.sh nc two-pointers                                    -> neetcode/two-pointers.cpp
#        ./new_solution.sh two-pointers                                       (same as above)
set -euo pipefail
cd "$(dirname "$0")"

if [ $# -eq 1 ]; then
    FILE="neetcode/$1.cpp"
elif [ $# -eq 2 ]; then
    if [ "$1" = "nc" ]; then
        FILE="neetcode/$2.cpp"
    else
        FILE="leetcode/$(printf "%04d" "$1")-$2.cpp"
    fi
else
    echo "Usage: $0 <problem-number|nc> <slug-with-dashes>"
    echo "       $0 <slug-with-dashes>   (defaults to nc)"
    exit 1
fi

if [ -e "$FILE" ]; then
    echo "Error: $FILE already exists"
    exit 1
fi

mkdir -p "$(dirname "$FILE")"
cat > "$FILE" <<EOF
#include "solution.h"

namespace {

class Solution {
public:
    void solve() {

    }
};

void run() {
    Solution sol;
}

}  // namespace

REGISTER_SOLUTION(run);
EOF

echo "Created $FILE"
