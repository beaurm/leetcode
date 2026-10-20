#include "solution.h"

namespace {

class Solution {
public:
    string encode(const vector<string>& strs) {
        string encoded {};

        for (auto str : strs) {
            encoded += to_string(str.length());
            encoded += 'x';
            encoded += str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        int ptr { 0 };
        int n_string { 0 };
        vector<string> result;
        while (ptr < s.length()) {
            string running_len {""};
            do {
                running_len += s[ptr];
                ++ptr;
            } while (s[ptr] != 'x');
            ++ptr;
            int real_running_len {std::stoi(running_len)};
            result.push_back("");
            for (int i { 0 }; i < real_running_len; ++i) {
                result[n_string] += s[ptr];
                ++ptr;
            }
            ++n_string;
        }
        return result;
    }
};

void run() {
    Solution sol;
    string encoded {sol.encode({"x9hello", "9xhello"})};
    vector decoded {sol.decode(encoded)};

    for (auto s : decoded) {
        cout << s << endl;
    }
}

}  // namespace

REGISTER_SOLUTION(run);
