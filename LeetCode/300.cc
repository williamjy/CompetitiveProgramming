#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

// dp
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> memo(nums.size(),1);
    memo[0] = 1;
    int result = 1;
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) memo[i] = memo[j] >= memo[i] ? memo[j]+1 : memo[i];
      }
      result = result > memo[i] ? result : memo[i];
    }
    return result;
  }
};

int main () {
  Solution solution;
  vector<int> nums{
    1,3,6,7,9,4,10,5,6
  };
  cout << solution.lengthOfLIS(nums) << endl;
}