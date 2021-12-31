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
    if (s1.size() > s2.size()) return isInterleave(s2,s1,s3);
    if (s1.size()+s2.size() != s3.size()) return 0;
    if (s1.size() == 0 && s2 == s3) return 1;
    if (s2.size() == 0 && s1 == s3) return 1;
    vector<bool> memo(s2.size()+1,0);
    for (int i = 0; i <= s1.size(); i++) {
      for (int j = 0; j <= s2.size(); j++) {
        if (!i && !j) {
          memo[j] = 1;
        } else if (!i && j) {
          memo[j] = memo[j-1] && (s2[j-1] == s3[j-1]);
        } else if (i && !j) {
          memo[j] = memo[j] && (s1[i-1] == s3[i-1]);
        } else {
          memo[j] = (memo[j] && (s1[i-1] == s3[i+j-1]) || memo[j-1] && (s2[j-1] == s3[i+j-1]));
        }
      }
    }
    return memo[s2.size()];
  }
};

int main () {
  Solution solution;
  string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
  cout << solution.isInterleave(s1,s2,s3) << endl;
}