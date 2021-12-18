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
      result[i] = result[i&(i-1)] + 1;
    }
    return result;
  }
};

int main () {
  Solution solution;
  for (auto i : solution.countBits(10)) cout << i << " ";
  cout << endl;
}