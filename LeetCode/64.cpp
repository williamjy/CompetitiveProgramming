#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int rows = grid.size();
    int columns = grid[0].size();
    vector<int> memo{0};
    for (auto i : grid[0]) memo.push_back(memo.back()+i);
    for (int i = 1; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        memo[j+1] = j && (memo[j] < memo[j+1]) ? memo[j] : memo[j+1];
        memo[j+1] += grid[i][j];
      }
    }
    return memo[columns];
  }
};

int main () {
  Solution solution;
  vector<vector<int>> grid {
    {1,3,1},
    {1,5,1},
    {4,2,1},
  };
  cout << solution.minPathSum(grid) << endl;
}