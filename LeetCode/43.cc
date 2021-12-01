#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> memo(n,10000);
    memo[0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= nums[i] && j < n-i; j++) {
        memo[i+j] = (memo[i+j] < memo[i]+1) ? memo[i+j] : memo[i]+1;
      }
    }
    return memo[n-1];
  }
};

int main () {
  Solution solution;
  vector<int> v{2,3,1,1,4};
  cout << solution.jump(v) << endl;

}