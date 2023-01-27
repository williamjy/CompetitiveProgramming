#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int minPos = 0;
        int secondMinPos = -1;
        for (int position = 1; position < nums.size(); position++) {
            if (secondMinPos > 0 && nums[position] > nums[secondMinPos]) {
                return true;
            }
            if (nums[position] > nums[minPos] && (secondMinPos == -1 || nums[position] < nums[secondMinPos])) {
                secondMinPos = position;
            }
            if (nums[position] < nums[minPos]) {
                minPos = position;
            }
        }
        return false;
    }
};