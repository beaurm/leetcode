#include "solution.h"

namespace {

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet;
        numsSet.reserve(nums.size());
        numsSet.insert(nums.begin(), nums.end());
        
        int longest { 0 };
        for (auto num: numsSet) {
            if (!numsSet.contains(num - 1)) {
                int length { 1 };
                while (numsSet.contains(num + length)) {
                    ++length;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }

};

void run() {
    Solution sol;
}

}  // namespace

REGISTER_SOLUTION(run);
