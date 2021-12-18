#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> result(n+1,0);
    for (int i = 1; i <= n; i++) {
      if (result[i]) continue;
      result[i] = countBit(i);
      for (int j = 2*i; j <= n; j*=2) {
        result[j] = result[i];
      }
    }
    return result;
  }
  int countBit(int n) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
      result += ((n >> i) & 1);
    }
    return result;
  }
};

int main () {
  Solution solution;
  for (auto i : solution.countBits(10)) cout << i << " ";
  cout << endl;
}