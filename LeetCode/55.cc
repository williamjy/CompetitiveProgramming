#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int max = nums[0];
    for (int i = 1; i <= max && i < n; i++) {
      max = (i + nums[i] > max) ? i + nums[i] : max;
    }
    return max >= n-1;
  }
};

int main () {
  Solution solution;
  vector<int> v{3,2,2,0,4};
  cout << solution.canJump(v) << endl;
}