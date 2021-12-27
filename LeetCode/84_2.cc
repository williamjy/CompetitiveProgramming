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
    int maximum = 0, p = 0;
    stack<int> height, position;
    height.push(heights[0]);
    position.push(0);
    for (int i = 0; i < heights.size(); i++) {
      if (heights[i] > height.top()) {
        height.push(heights[i]);
        position.push(i);
      } else {
        p = -1;
        while (height.size() && height.top() >= heights[i]) {
          p = position.top();
          maximum = max(maximum,(i-position.top())*height.top());
          height.pop();
          position.pop();        
        }
        height.push(heights[i]);
        position.push(p == -1 ? i : p);
      }
    }
    while (height.size()) {
      maximum = max(maximum,(int) (heights.size()-position.top())*height.top());
      height.pop();
      position.pop();
    }
    return maximum;
  }
};

int main () {
  Solution solution;
  vector<int> v{2, 1, 5, 6, 2, 3};
  cout << solution.largestRectangleArea(v) << endl;
}