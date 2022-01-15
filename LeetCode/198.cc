#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    int prev3 = 0, prev2 = 0, prev1 = 0, curr = 0;
    for (int i = 0; i < nums.size(); i++) {
      prev3 = prev2;
      prev2 = prev1;
      prev1 = curr;
      curr = prev3  > prev2 ? prev3 + nums[i] : prev2 + nums[i];
    }
    return prev1 > curr ? prev1 : curr;
  }
};

int main () {
    Solution solution;
  vector<int> dungeon{
    1,2,3,1
  };
  cout << solution.rob(dungeon) << endl;
}