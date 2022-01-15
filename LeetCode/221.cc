#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    vector<int> memo(matrix[0].size(),0);
    int result = 0;
    for (int i = 0; i < matrix.size(); i++) {
      int prev = 300, tmp = 300;
      for (int j = 0; j < matrix[0].size(); j++) {
        if (!j) {
          prev = memo[j];
          memo[j] = matrix[i][j] - '0';
        } else {
          tmp = memo[j];
          memo[j] = matrix[i][j] == '1' ? getMin(prev,memo[j-1],memo[j])+1 : 0;
          prev = tmp;
        }
        result = result > memo[j] ? result : memo[j];
      }
    }
    return result*result;
  }
  int getMin(int a, int b, int c) {
    return a < b ? (a < c) ? a :c : (b < c) ? b : c;
  }
};

int main () {
  Solution solution;
  vector<vector<char>> v{
    {'1','0','1','0'},
    {'1','0','1','1'},
    {'1','0','1','1'},
    {'1','1','1','1'},
  };
  cout << solution.maximalSquare(v) << endl;
}