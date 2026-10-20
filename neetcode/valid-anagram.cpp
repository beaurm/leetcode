#include "solution.h"

namespace {

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        uint16_t count[26] = {0};

        for (char c : s) count[c - 'a']++;
        for (char c : t) count[c - 'a']--;
        for (int x : count) if (x != 0) return false;
        return true;
    }
};

void run() {
    Solution sol;
    std::cout << sol.isAnagram("abc", "cba");
}

}  // namespace

REGISTER_SOLUTION(run);
