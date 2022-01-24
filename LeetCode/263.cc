#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
  bool isUgly(int n) {
    while (n) {
      if (n % 2 == 0) {
        n /= 2;
      } else if (n % 3 == 0) {
        n /= 3;
      } else if (n % 5 == 0) {
        n /= 5;
      } else {
        break;
      }
    }
    return n == 1;
  }
};

int main () {
  Solution solution;
  int n = 5;
  cout << solution.isUgly(n) << endl;
}