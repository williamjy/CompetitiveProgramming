#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    if (n <= 1) return s;
    int x = 0,y = 0;
    for (int i = 0; i < n-1; i++) {
      int j = 0;
      for (; j < n-i-1 && j <= i; j++) {
        if (s[i-j] != s[i+1+j]) break;
      }
      j--;
      if (2 * j + 2 > y-x+1) {
        x = i-j;
        y = i+1+j;
      }
      // cout << "first i " << i << " j " << j << " x " << x << " y " << y << endl;
    }
    for (int i =0; i < n; i++) {
      int j = 0;
      for (j; j < n-i && j <= i; j++) {
        if (s[i-j] != s[i+j]) break;
      }
      j--;
      if (2 * j + 1 > y-x+1) {
        x = i-j;
        y = i+j;
      }
      // cout << "second i " << i << " j " << j << " x " << x << " y " << y << endl;
    }
    return s.substr(x,y-x+1);
  }
};

int main () {
  Solution solution;
  string s = "babad";
  cout << solution.longestPalindrome(s) << endl;
}