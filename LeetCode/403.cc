#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
  bool canCross(vector<int>& stones) {
    if (stones[1]-stones[0]!=1) return 0;
    // start at i, end on j
    vector<vector<bool>> memo(stones.size(),vector<bool>(stones.size(),0));
    memo[0][1] = 1;
    // i = curr
    for (int i = 1; i < stones.size()-1; i++) {
      for (int j = 0; j < i; j++) {
        if (memo[j][i] == 0) continue;
        int diff = stones[i]-stones[j];
        for (int k = i+1; k < stones.size(); k++) {
          int dist = stones[k]-stones[i] - diff;
          if (dist>1) break;
          if (dist >= -1 && dist <= 1) memo[i][k] = 1;
        }

      }
      // cout << "i " << i << endl;
      // for (auto a : memo) {
      //   for (auto b : a) {
      //     cout << b << " ";
      //   }
      //   cout << endl;
      // }
      // cout << endl;
    }
    for (int i = 0; i < stones.size(); i++) {
      if (memo[i][stones.size()-1]) return true;
    }
    return false;
  }
};

int main () {
  Solution solution;
  vector<int> stones{
    0,1,3,5,6,8,12,17
  };
  cout << solution.canCross(stones) << endl;
}