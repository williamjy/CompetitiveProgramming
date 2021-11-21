#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    int stairs[n+1];
    stairs[0] = 1;
    stairs[1] = 1;
    for (int i = 2; i <= n; i++) {
      stairs[i] = stairs[i-2]+stairs[i-1];
    } 
    return stairs[n];
  }
};

int main () {
  Solution s;
  int v = 4;
  cout << s.climbStairs(v) << endl;

}