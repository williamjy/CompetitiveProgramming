#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int total = 0;
        bool flipped = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k and nums[i-k] > 1) {
                nums[i-k] -= 2;
                flipped = !flipped;
            }
            if (nums[i] == flipped) {
                if (i > nums.size()-k) {
                    return -1;
                }
                nums[i] += 2;
                ++total;
                flipped = !flipped;
            }
        }
        return total;
    }
};