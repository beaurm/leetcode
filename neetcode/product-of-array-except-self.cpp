#include "solution.h"

namespace {

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        vector<int> result;

        int cumul = 1;
        for (int i {0}; i < nums.size() -1; ++i) {
            cumul *= nums[i];
            prefix[i] = cumul;
        }

        cumul = 1;
        for (int i = nums.size() - 1; i > 0; --i) {
            cumul *= nums[i];
            suffix[i] = cumul;
        }

        result.push_back(suffix[1]);
        for (int i {1}; i < nums.size() - 1; ++i) {
            result.push_back(prefix[i-1] * suffix[i+1]);
        }
        result.push_back(prefix[nums.size() - 2]);

        return result;
    }
};

void run() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    vector<int> res = sol.productExceptSelf(nums);

    for (auto i : res) {
        std::cout << i << std::endl;
    }
}

}  // namespace

REGISTER_SOLUTION(run);
