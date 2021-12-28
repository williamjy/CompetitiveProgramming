#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int maximum = 0;
    vector<int> memo(m+1,0);
    for (int row = 0; row < n; row++) {
      for (int column = 0; column < m; column++) {
        memo[column] = matrix[row][column] == '0' ? 0 : memo[column]+1;
      }
      if (matrix[row].size() == 1) {
        maximum = max(maximum, memo[0]);
        continue;
      }
      stack<int> stack;
      for (int i = 0; i < memo.size(); i++) {
        while (stack.size() && memo[stack.top()] > memo[i]) {
          int h = memo[stack.top()];
          stack.pop();
          int p = stack.empty() ? -1 : stack.top();
          maximum = max(maximum,h*(i-p-1));
        }
        stack.push(i);
      }
    }
    return maximum;
  }
};

int main () {
  Solution solution;
  vector<vector<char>> v{
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'},
  };
  cout << solution.maximalRectangle(v) << endl;
}