#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

// dp with memo.
class Solution {
private:
  vector<int> memo = vector<int> (10001,0);
public:
  int numSquares(int n) {
    int result = 10000, curr = 0;
    if (n == 0) return 0;
    if (memo[n]) return memo[n];
    for (int i = sqrt(n); i > 0; i--) {
      curr = numSquares(n - i*i);
      result = curr < result ? curr+1 : result;
    }
    memo[n] = result;
    return memo[n];
  }
};

int main () {
  Solution solution;
  int n = 9999;
  cout << solution.numSquares(n) << endl;
}