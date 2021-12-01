#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int length = s.size();
    bool memo[length][length];
    int x,y,max = 0;
    for (int i = length-1; i >= 0; i--) {
      for (int j = i; j < length; j++) {
        if (i == j) {
          memo[i][j] = true;
          if (max < j-i) {
            max = j-i;
            x = i;
            y = j;
          }
        } else if (i + 1 == j) {
          if (s[i] == s[j]) {
            memo[i][j] = true;
            if (max < j-i) {
              max = j-i;
              x = i;
              y = j;
            }
          } else {
            memo[i][j] = false;
          }
        } else {
          if (s[i] == s[j]) {
            memo[i][j] = memo[i+1][j-1];
            if (memo[i][j]) {
              if (max < j-i) {
                max = j-i;
                x = i;
                y = j;
              }
            }
          } else {
            memo[i][j] = false;
          }
        }
      }
    }
    return s.substr(x,y-x+1);
  }
};

int main () {
  Solution solution;
  string s = "cbbd";
  cout << solution.longestPalindrome(s) << endl;
}