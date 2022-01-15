#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    int prev2 = 0, prev1 = 0, tmp = 0, result = 0;
    for (int i = 0; i < nums.size()-1; i++) {
      tmp = prev1;
      prev1 = prev2 + nums[i] > prev1 ? prev2 + nums[i] : prev1;
      prev2 = tmp;
    }
    result = prev1 > prev2 ? prev1 : prev2;
    prev2 = 0, prev1 = 0;
    for (int i = 1; i < nums.size(); i++) {
      tmp = prev1;
      prev1 = prev2 + nums[i] > prev1 ? prev2 + nums[i] : prev1;
      prev2 = tmp;
    }
    result = prev1 > prev2 ? (prev1 > result) ? prev1 : result : (prev2 > result) ? prev2 : result;
    return result;
  }
};

int main () {
    Solution solution;
  vector<int> dungeon{
    1,2,3,1
  };
  cout << solution.rob(dungeon) << endl;
}