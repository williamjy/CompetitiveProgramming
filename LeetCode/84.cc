#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    if (heights.size() == 1) return heights[0];
    int maximum = 0;
    heights.push_back(0);
    stack<int> memo;
    for (int i = 0; i < heights.size(); i++) {
      while (memo.size() && heights[memo.top()] > heights[i]) {
        int h = heights[memo.top()]; memo.pop();
        int l = memo.empty() ? -1 : memo.top();
        maximum = max(maximum, h * (i - l - 1));
      }
      memo.push(i);
    }
    return maximum;
  }
};

int main () {
  Solution solution;
  vector<int> v{2, 1, 2};
  cout << solution.largestRectangleArea(v) << endl;
}