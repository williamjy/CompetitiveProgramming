#include <vector>
#include <stack>
#include <math.h>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int lastNumber = INT_MIN;
        stack<int> middleNumberCandidateStack;
        for (int i = nums.size() - 1; i >= 0; --i) {
                if (nums[i] < lastNumber)
                {
                    return true;
                }
                while (!middleNumberCandidateStack.empty() && middleNumberCandidateStack.top() < nums[i])
                {
                    lastNumber = middleNumberCandidateStack.top();
                    middleNumberCandidateStack.pop();
                }
                middleNumberCandidateStack.push(nums[i]);
            }
        return false;
    }
};