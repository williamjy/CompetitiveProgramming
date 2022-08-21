#include <vector>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxAtI = nums[0], minAtI = nums[0], max = nums[0], tmp;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                tmp = maxAtI;
                maxAtI = minAtI;
                minAtI = tmp;
            }
            maxAtI = maxAtI * nums[i];
            minAtI = minAtI * nums[i];
            maxAtI = maxAtI > nums[i] ? maxAtI : nums[i];
            minAtI = minAtI < nums[i] ? minAtI : nums[i];
            max = max > maxAtI ? max : maxAtI;
        }
        return max;
    }
};