#include "solution.h"

namespace {

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < (int)nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.count(complement)) return {seen[complement], i};
            seen[nums[i]] = i;
        }
        return {};
    }
};

void run() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    auto result = sol.twoSum(nums, 9);
    for (int x : result) cout << x << " ";
    cout << endl;
}

}  // namespace

REGISTER_SOLUTION(run);
