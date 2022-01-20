#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    int copy = x, y = 0;
    while (copy) {
      if (y > 0x7FFFFFFF / 10) return false;
      y *= 10;
      y += (copy % 10);
      copy /= 10;
    }
    return x >= 0 && x == y;
  }
};

int main () {
  Solution solution;
  int x = 1234567899;
  cout << solution.isPalindrome(x) << endl;
}