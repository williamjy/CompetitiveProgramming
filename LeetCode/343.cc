#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
  int integerBreak(int n) {
    vector<int> memo(n+1,1);
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        int curr = j > memo[j] ? j : memo[j];
        curr = i-j > memo[i-j] ? curr*(i-j) : curr * memo[i-j];
        memo[i] = memo[i] > curr ? memo[i] : curr;
      }
    }
    return memo[n];
  }
};

int main () {
  Solution solution;
  int n = 58;
  cout << solution.integerBreak(n) << endl;
}