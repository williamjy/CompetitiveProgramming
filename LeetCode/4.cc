#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size();
        int length2 = nums2.size();
        if (length1 > length2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        bool isOdd = (length1 + length2) % 2;
        int medianPosition = (length1 + length2 + 1) / 2;
        for (int cut1 = 0; cut1 <= length1; cut1++) {
            int cut2 = medianPosition - cut1;
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int right1 = cut1 == length1 ? INT_MAX : nums1[cut1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int right2 = cut2 == length2 ? INT_MAX : nums2[cut2];
            if (left1 <= right2 && left2 <= right1) {
                if (isOdd) {
                    return left1 > left2 ? left1 : left2;
                } else {
                    return ((left1 > left2 ? left1 : left2) +  (right1 < right2 ? right1 : right2)) / 2.0;
                }
            }
        }
        return -1000000;
    }
};