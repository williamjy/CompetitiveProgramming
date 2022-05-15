#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int getAbsDiff(int a, int b) {
        return a < b ? b-a : a-b;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest = -30000;
        for (int i = 0; i < nums.size()-2; i++) {
            int j = i+1, k = nums.size() - 1;
            int curr;
            while (j < k) {
                curr = nums[i] + nums[j] + nums[k];
                if (target-curr == 0) return curr;
                else if (target - curr < 0) {
                    k--;
                } else {
                    j++;
                }
                closest = getAbsDiff(closest,target) < getAbsDiff(curr,target) ? closest : curr;
            }
        }
        return closest;
    }
};

int main () {
    Solution solution;
    vector<int> nums{
        1,2,5,10,11
    };
    // vector<int> nums{
    //     -5,-5,-4,0,0,3,3,4,5
    // };
    auto s = solution.threeSumClosest(nums,12);
    cout << s << endl;
    return 0;
}