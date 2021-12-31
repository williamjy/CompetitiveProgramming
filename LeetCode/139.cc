#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> memo(s.size()+1,0);
    memo[0] = 1;
    for (int i = 1; i <= s.size(); i++) {
      for (int j = i-1; j >= 0; j--) {
        if (memo[j] && find(wordDict.begin(),wordDict.end(),s.substr(j,i-j)) != wordDict.end()) {
          memo[i] = 1;
          break;
        }
      }
    }
    return memo[s.size()];
  }
};

int main () {
  Solution solution;
  string s = "applepenapple";
  vector<string> v{"apple","pen"};
  cout << solution.wordBreak(s,v) << endl;
}