#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
  int trap(vector<int>& height) {
    int l = 0, r = height.size()-1, level = 0, water = 0;
    while (l < r) {
      int lower = height[height[l] < height[r] ? l++ : r--];
      level = max(level, lower);
      water += level - lower;
    }
    return water;
  }
};

int main () {
  Solution solution;
  vector<int> v{5,4,3,2};
  cout << solution.trap(v) << endl;

}