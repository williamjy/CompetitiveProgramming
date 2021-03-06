#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int rows = obstacleGrid.size();
    int columns = obstacleGrid[0].size();
    vector<int> memo(columns+1,0);
    memo[1] = 1;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        if (obstacleGrid[i][j]) memo[j+1] = 0;
        else memo[j+1] += memo[j];
      }
    }
    return memo[columns];
  }
};

int main () {
  Solution solution;
  vector<vector<int>> obstacleGrid {
    {0,0,0},
    {0,1,0},
    {0,0,0},
  };
  cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;
}