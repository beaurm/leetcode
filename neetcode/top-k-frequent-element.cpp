#include "solution.h"

namespace {

//Bucket sort: you can implicitly sort something by putting it at the correct indices of an array. For exaple you could sort in O(n) uint8 array
// Count how many of each uint8 there are and place those counts in an array (uint8 val idx-> count). Then just itterate over that array and append the indices count times
//You will get a sorted array.

//Here we dont need to sort the values but we need sorted counts so we do: compute the counts: (val -> count hashmap)
//Then bucket sort the counts -> value (counts as indexes, values as values) so we get values sorted by count pretty much. Opposite of example above.en
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> vals_at_count(nums.size() + 1);
        unordered_map<int, int> map {};

        for (int num : nums) {
            map[num]++;
        }

        for (auto count_p : map) {
            vals_at_count[count_p.second].push_back(count_p.first);
        }

        vector<int> result;

        for (size_t i { vals_at_count.size() - 1 }; i > 0; --i) {
            for (auto val : vals_at_count[i]) {
                result.push_back(val);
                --k;

                if (k == 0) return result;
            }
        }

        return result;
    }
};

void run() {
    vector<int> nums {7,7};
    Solution sol;
    vector<int> result = sol.topKFrequent(nums, 1);

    for (int num : result) {
        cout << num << " ";
    }
}

}  // namespace

REGISTER_SOLUTION(run);
