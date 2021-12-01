#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int s_size = s.size();
    int p_size = p.size();
    vector<vector<bool>> memo(p_size+1,vector<bool>(s_size+1,false));
    memo[0][0] = true;
    for (int i = 1; i <= p_size; i++) {
      for (int j = 0; j <= s_size; j++) {
        if (p[i-1] != '*') memo[i][j] = j && memo[i-1][j-1] && (s[j-1] == p[i-1] || p[i-1] == '?');
        else memo[i][j] = memo[i-1][j] || (j && memo[i][j-1]);
      }
    }
    return memo[p_size][s_size];
  }
};

int main () {
  Solution solution;
  string s = "aab";
  string p = "c*a*b";
  cout << solution.isMatch(s,p) << endl;

}