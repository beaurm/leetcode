#include "solution.h"

namespace {

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* out = new ListNode();

        while (l1 || l2) {
            bool reminder = false;
            bool next = false;
            int l1_val = 0;
            int l2_val = 0;
            if (l1) {
                l1_val = l1->val;
                l1 = l1->next;
                next = true;
            }
            if (l2) {
                l2_val = l2->val;
                l2 = l2->next;
                next = true;
            }
            int res = l1_val + l2_val + out -> val;

            if (res >= 10) {
                reminder = true;
                res -= 10;
            }

            out-> val += res;

            if (next || reminder) {
                out->next = new ListNode();
                out = out -> next;
                if (reminder) {
                    out -> val += 1;
                }
            }

        }

        return out;

    }
};

void run() {
    Solution s;
}

}  // namespace

REGISTER_SOLUTION(run);
