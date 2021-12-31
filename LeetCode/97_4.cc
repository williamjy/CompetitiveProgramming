#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size()+s2.size() != s3.size()) return 0;
    if (s1.size() == 0 && s2 == s3) return 1;
    if (s2.size() == 0 && s1 == s3) return 1;
    vector<vector<bool>> memo(s1.size()+1,vector<bool>(s2.size()+1,0));
    memo[0][0] = 1;
    for (int i = 1; i <= s1.size(); i++) {
      memo[i][0] = memo[i-1][0] && (s1[i-1] == s3[i-1]);
    }
    for (int j = 1; j <= s1.size(); j++) {
      memo[0][j] = memo[0][j-1] && (s2[j-1] == s3[j-1]);
    }
    for (int i = 1; i <= s1.size(); i++) {
      for (int j = 1; j <= s2.size(); j++) {
        memo[i][j] = (memo[i-1][j] && (s1[i-1] == s3[i+j-1]) || memo[i][j-1] && (s2[j-1] == s3[i+j-1]));
      }
    }
    return memo[s1.size()][s2.size()];
  }
};

int main () {
  Solution solution;
  string s1 = "", s2 = "b", s3 = "b";
  cout << solution.isInterleave(s1,s2,s3) << endl;
}