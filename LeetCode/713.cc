#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1, result = 0, start = 0, end = 0, prevEnd = 0;
        for (; end < nums.size(); ++end) {
            product *= nums[end];
            if (product >= k) {
                result += (end - start) * (end - start + 1) / 2;
                result -= (prevEnd - start) * (prevEnd - start + 1) / 2;
                prevEnd = end;
                while (product >= k && start < end) {
                    product /= nums[start++];
                }
            }
        }
        result += (nums.size() - start) * (nums.size() - start + 1) / 2;
        result -= (prevEnd - start) * (prevEnd - start + 1) / 2;
        return result;
    }
};

int main() {
    vector<int> v{
        10,5,2,6
    };
    Solution solution;
    cout << solution.numSubarrayProductLessThanK(v, 100) << endl;
}