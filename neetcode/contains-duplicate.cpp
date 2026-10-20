#include "solution.h"

namespace {

class Solution {
public:

    bool hasDuplicate(vector<int>& nums) {

        unordered_map<int, bool> mp {};

        for (int i : nums) {
            if (mp.contains(i)) {
                return true;
            }
            mp[i] = true;
        }

        return false;
    }
};

void run() {
    Solution sol;
    vector<int> x {1,2,3,3,5};
    cout << sol.hasDuplicate(x);
}

}  // namespace

REGISTER_SOLUTION(run);
