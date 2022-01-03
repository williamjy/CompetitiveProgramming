#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minCut(string s) {
    vector<vector<bool>> palindrome(s.size(),vector<bool>(s.size(),0));
    vector<int> memo(s.size(),s.size());
    memo[0] = 1;
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j <= min(i-0,(int) s.size()-i-1); j++) {
        if (!j) {
          palindrome[i][i] = 1;
        } else {
          palindrome[i-j][i+j] = palindrome[i-j+1][i+j-1] && s[i-j] == s[i+j];
        }
      }
    }
    for (int i = 0; i < s.size()-1; i++) {
      for (int j = 0; j <= min(i-0,(int) s.size()-i-2); j++) {
        if (!j) {
          palindrome[i][i+1] = s[i] == s[i+1];
        } else {
          palindrome[i-j][i+j+1] = palindrome[i-j+1][i+j] && s[i-j] == s[i+j+1];
        }
      }
    }
    for (int i = 1; i < s.size(); i++) {
      if (palindrome[0][i]) {
        memo[i] = 1;
        continue;
      }
      for (int j = 1; j <= i; j++) {
        if (palindrome[j][i]) {
          memo[i] = memo[i] < memo[j-1]+1 ? memo[i] : memo[j-1]+1;
        }
      }
    }
    return memo[s.size()-1]-1;
  }
};

int main () {
  Solution solution;
  string s = "aabb";
  cout << solution.minCut(s) << endl;
}