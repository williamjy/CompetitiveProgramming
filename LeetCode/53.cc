#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int end = nums.size();
    int max = *nums.begin();
    int sum = 0;
    for (auto i : nums) {
      sum += i;
      max = (max > sum) ? max : sum;
      if (sum < 0) sum = 0;
    }
    return max;
  }
};

int main () {
  Solution s;
  vector<int> v {-2,1,-3,4};
  cout << s.maxSubArray(v) << endl;

}