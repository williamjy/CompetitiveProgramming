#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();
    vector<int>dp(n, 1e5 + 1);
    int currNeed;
    for (int i = m-1; i >= 0; i--) {
      for (int j = n-1; j >= 0; j--) {
        if (i == m-1) {
          if (j == n-1) {
            dp[j] = dungeon[i][j] <= 0 ? 1 - dungeon[i][j] : 1;
          } else {
            dp[j] = dungeon[i][j] <= 0 ? dp[j+1] - dungeon[i][j] : dungeon[i][j] < dp[j+1] ? dp[j+1] - dungeon[i][j] : 1;
          }
        } else {
          if (j == n-1) {
            dp[j] = dungeon[i][j] <= 0 ? dp[j] - dungeon[i][j] : dungeon[i][j] < dp[j] ? dp[j] - dungeon[i][j] : 1;
          } else {
            int less = dp[j] < dp[j+1] ? dp[j] : dp[j+1];
            dp[j] = dungeon[i][j] <= 0 ? less - dungeon[i][j] : dungeon[i][j] < less ? less - dungeon[i][j] : 1;
          }
        }
      }
    }
    return dp[0];
  }
};

int main () {
  Solution solution;
  vector<vector<int>> dungeon{
    {1,-3,3},
    {0,-2,0},
    {-3,-3,-3},
  };
  cout << solution.calculateMinimumHP(dungeon) << endl;
}