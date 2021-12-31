#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

// 1050 ms
class Solution {
private:
  map<string,bool> memo;
public:
  bool isInterleave(string s1, string s2, string s3) {
    return rec(s1,s2,s3) || rec(s2,s1,s3);
  }

  bool rec(string s1, string s2, string s3) {
    if (s1+s2 == s3) return memo[s1+s2+s3] = true;
    if (s1.size()+s2.size()!=s3.size()) return false;
    if (s1.size() == 0) return false;
    if (this->memo.find(s1+s2+s3) != memo.end()) return memo[s1+s2+s3];
    for (int i = 0; i < s1.size()-1; i++) {
      if (s1[i] != s3[i]) break;
      if (rec(s2,s1.substr(i+1),s3.substr(i+1))) return memo[s1+s2+s3] = true;;
    }
    return memo[s1+s2+s3] = false;
  }
};

int main () {
  Solution solution;
  string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
  cout << solution.isInterleave(s1,s2,s3) << endl;
}