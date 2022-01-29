#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> memo(amount+1,100001);
    memo[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (auto j : coins) {
        if (i >= j) memo[i] = memo[i-j] < memo[i] ? memo[i-j]+1 : memo[i];
      }
    }
    return memo.back() == 100001 ? -1 : memo.back();
  }
};

int main () {
  Solution solution;
  vector<int> coins{
    1
  };
  int amount = 5;
  cout << solution.coinChange(coins,amount) << endl;
}