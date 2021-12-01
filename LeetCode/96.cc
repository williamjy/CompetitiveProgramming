#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int numTrees(int n) {
    vector<int> memo(n+1,0);
    memo[0] = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum = 0;
      for (int j = 1; j <= i; j++) {
        sum += memo[j-1] * memo[i-j];
      }
      memo[i] = sum;
    }
    return memo[n];
  }
};

int main () {
  Solution solution;
  int n = 19;
  cout << solution.numTrees(n) << endl;

}