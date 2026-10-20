#include "solution.h"

namespace {

class Solution {
public:
    double solve(vector<int>& nums1, vector<int>& nums2) {
        int tot_length = nums1.size() + nums2.size();

        bool is_pair = tot_length % 2 == 0;
        int med = tot_length / 2;
        int i = 0;
        int j = 0;

        int  previous = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                if (i + j == med) {
                    if (is_pair) {
                        return double(previous + nums1[i]) / 2;
                    }
                    return nums1[i];
                }
                previous = nums1[i];
                i++;
            }
            else {
                if (i + j == med) {
                    if (is_pair) {
                        return double(previous + nums2[j]) / 2;
                    }
                    return nums2[j];
                }
                previous = nums2[j];
                j++;
            }
        }

        while (i < nums1.size() ) {
            if (i + j == med) {
                if (is_pair) {
                    return double(previous + nums1[i]) / 2;
                }
                return nums1[i];
            }
            previous = nums1[i];
            i++;
        }

        while (j < nums2.size() ) {
            if (i + j == med) {
                if (is_pair) {
                        return double(previous + nums2[j]) / 2;
                }
                return nums2[j];
            }
            previous = nums2[j];
            j++;
        }

        return 0;
    }
};

//Pas ma solution
// Problème demandait O(log (m + n) comme complexité ce que ma solution n'avait pas
// O(log x) indique qu'il faut probablement utiliser binary search
//

class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size();
        const int n2 = nums2.size();

        //I like this trick to not have to always manage left and right dependencies weirdly
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int l = 0;
        int r = n1;

        while (l <= r) {
            const int partition1 = (l + r) / 2;
            const int partition2 = (n1 + n2 + 1) / 2 - partition1; //Left partition of num 2 is the number of element global partition should have - number of element 1
            const int maxLeft1 = partition1 == 0 ? INT_MIN : nums1[partition1 - 1];
            const int maxLeft2 = partition2 == 0 ? INT_MIN : nums2[partition2 - 1];
            const int minRight1 = partition1 == n1 ? INT_MAX : nums1[partition1];
            const int minRight2 = partition2 == n2 ? INT_MAX : nums2[partition2];
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) //Correct partition is chose
                return (n1 + n2) % 2 == 0
                           ? (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) * 0.5
                           : max(maxLeft1, maxLeft2);
            else if (maxLeft1 > minRight2)
                r = partition1 - 1; //We retry with one less element from the mid point
            else
                l = partition1 + 1; //Take one more element, same thing..

            //l could get higher than elements that should be included thats fine, it only restrains the window in which the midpoint is
            //Thats the whole point of the binary search here.
        }

        throw;
    }
};

void run() {
    Solution sol;

    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    std::cout << sol.solve(nums1, nums2);
}

}  // namespace

REGISTER_SOLUTION(run);
