#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
  int reverse(int x) {
    int result = 0, tmp;
    while(x) {
      if ((result > 0 && result > ((int) 0x7FFFFFFF -x%10)/10) || (result < 0 && result < ((int) 0x80000000 - x%10)/10)) return 0;
      result = result * 10 + x % 10;
      x /= 10;
    }
    return result;
  }
};

int main () {
  Solution solution;
  cout << solution.reverse(123) << endl;
}