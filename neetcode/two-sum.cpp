#include "solution.h"

namespace {

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, uint16_t> seen_indices;

        for (uint16_t i {}; i < nums.size(); i++) {
            const int remainder { target - i };

            auto it = seen_indices.find(remainder);

            if (it != seen_indices.end()) {
                return vector<int> {it->first, i};
            }

            seen_indices[nums[i]] = i;

        }
        return {};
    }
};

void run() {
    Solution sol;
}

}  // namespace

REGISTER_SOLUTION(run);
