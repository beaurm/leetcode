#include "solution.h"

namespace {

class Solution {
public:
    int solve(string s) {
        int max = 0;
        std::bitset<256> seen;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            int j = 0;
            while (true) {
                if (seen[(unsigned char) s[i + j]]) {
                    break;
                }

                seen[(unsigned char) s[i + j]] = true;
                j += 1;
                if (i + j >= size) break;
            }

            if (j > max) {
                max = j;
            }
            seen.reset();
        }

        return max;
    }
};

void run() {
    Solution sol;
    std::cout << sol.solve("abcabcbb") << std::endl;
}

}  // namespace

REGISTER_SOLUTION(run);
