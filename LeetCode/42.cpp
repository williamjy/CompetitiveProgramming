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
    int n = height.size();
    stack<int> stack;
    stack.push(0);
    int result = 0,max = 0;
    for (int i = 1; i < n; i++) {
      if (stack.empty()) continue;
      int prev = stack.top(),curr = -1;
      int h = (height[max] < height[i]) ? height[max] : height[i];
      while (!stack.empty()) {
        curr = stack.top();
        result += (h-height[prev]) * (prev-curr);
        prev = curr;
        if (height[prev] > height[i]) break;
        stack.pop();
      }
      max = (height[i] > height[max]) ? i : max;
      stack.push(i);
    }
    return result;
  }
};

int main () {
  Solution solution;
  vector<int> v{4,2,0,3,2,5};
  cout << solution.trap(v) << endl;

}