#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int s_size = s.size();
    int p_size = p.size();
    vector <vector<bool>> memo(s_size+1,vector<bool>(p_size+1,false));
    memo[0][0] = true;
    for (int i = 0; i <= s_size; i++) {
        for (int j = 1; j <= p_size; j++) {
          if (p[j-1] == '*') memo[i][j] = memo[i][j-2] || (i && memo[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
          else if (i > 0) memo[i][j] = memo[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
      }
    }
    return memo[s_size][p_size];
  }
};

int main () {
  Solution solution;
  string s = "mississippi";
  string p = "mis*is*p*.";
  cout << solution.isMatch(s,p) << endl;

}