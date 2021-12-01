#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    int s = (m < n) ? m : n;
    int l = (m > n) ? m : n;
    vector<int> memo(s+1,1);
    memo[0] = 0;
    for (int i = 1; i < l; i++) {
      for (int j = 1; j <= s; j++) {
        memo[j] += memo[j-1];
      }
    }
    return memo[s];
  }
};

int main () {
  Solution solution;
  cout << solution.uniquePaths(3,7) << endl;
}