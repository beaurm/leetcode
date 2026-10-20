#include "solution.h"

namespace {

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> result_map {};

        for (auto& str : strs) {
            string hash(26, 0);
            for (auto c : str) {
                hash[c - 'a']++;
            }

            result_map[hash].push_back(str);
        }

        vector<vector<string>> groupAnagrams {};
        groupAnagrams.reserve(result_map.size());

        for (auto& result: result_map) {
            groupAnagrams.push_back(std::move(result.second));
        }

        return groupAnagrams;
    }
};

void run() {
    Solution sol;
    vector<string> strs {"", "a", "aa", "ab", "ba"};
    vector<vector<string>> res = sol.groupAnagrams(strs);

    for (auto strs: res) {
        for (auto str2: strs) {
            cout << str2 << endl;
        }
    }
}

}  // namespace

REGISTER_SOLUTION(run);
