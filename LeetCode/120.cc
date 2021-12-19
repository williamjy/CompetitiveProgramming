#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> memo = triangle[n-1];
    for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j < triangle[i].size(); j++) {
        memo[j] = memo[j] < memo[j+1] ? memo[j] + triangle[i][j] : memo[j+1] + triangle[i][j];
      }
    }
    return memo[0];
  }
};

int main () {
  Solution solution;
  vector<vector<int>> triangle{
    {-7},
    {-2,1},
    {-5,-5,9},
    {-4,-5,4,4},
    {-6,-6,2,-1,-5},
    {3,7,8,-3,7,-9},
    {-9,-1,-9,6,9,0,7},
    {-7,0,-6,-8,7,1,-4,9},
    {-3,2,-6,-9,-7,-6,-9,4,0},
    {-8,-6,-3,-9,-2,-6,7,-5,0,7},
    {-9,-1,-2,4,-2,4,4,-1,2,-5,5},
    {1,1,-6,1,-2,-4,4,-2,6,-6,0,6},
    {-3,-3,-6,-2,-6,-2,7,-9,-5,-7,-5,5,1}
  };
  cout << solution.minimumTotal(triangle) << endl;
}