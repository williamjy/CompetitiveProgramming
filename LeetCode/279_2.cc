#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

// static dp.
class Solution {
public:
  int numSquares(int n) {
    static vector<int> memo {0};
    if (memo.size() > n) return memo[n];
    while (memo.size() <= n) {
      // calculate numSquares of m and push it to the memo.
      int m = memo.size(), mNumSquares = 10000;
      for (int i = 1; i*i <= m; i++) {
        mNumSquares = memo[m-i*i] < mNumSquares ? memo[m-i*i]+1 : mNumSquares;
      }
      memo.push_back(mNumSquares);
    }
    return memo[n];
  }
};

int main () {
  Solution solution;
  int n = 9999;
  cout << solution.numSquares(n) << endl;
}