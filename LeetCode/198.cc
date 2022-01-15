#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    int prev2 = 0, prev1 = 0, tmp = 0;
    for (int i = 0; i < nums.size(); i++) {
      tmp = prev1;
      prev1 = prev2 + nums[i] > prev1 ? prev2 + nums[i] : prev1;
      prev2 = tmp;
    }
    return prev1 > prev2 ? prev1 : prev2;
  }
};

int main () {
    Solution solution;
  vector<int> dungeon{
    1,2,3,1
  };
  cout << solution.rob(dungeon) << endl;
}