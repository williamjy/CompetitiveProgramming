#include <vector>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> uglies(n,1);
    int a = 0, b = 0, c = 0;
    for (int i = 1; i < n; i++) {
      int t = minimum (uglies[a] * 2, uglies[b] * 3, uglies[c] * 5);
      uglies[i] = t;
      if (t == uglies[a] * 2) a++;
      if (t == uglies[b] * 3) b++;
      if (t == uglies[c] * 5) c++;
    }
    return uglies.back();
  }
  int minimum(int a, int b, int c) {
    return a < b ? a < c ? a : c : b < c ? b : c;
  }
};

int main () {
  Solution solution;
  int n = 8;
  cout << solution.nthUglyNumber(n) << endl;
}