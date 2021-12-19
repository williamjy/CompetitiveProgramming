#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int numDistinct(string s, string t) {
    int s_size = s.size(), t_size = t.size();
    vector<int> memo(s_size+1,1);
    for (int i = 0; i < t_size; i++) {
      int prev = memo[0];
      int tmp = 0;
      memo[0] = 0;
      for (int j = 0; j < s_size; j++) {
        if (t[i] == s[j]) {
          tmp = memo[j+1];
          memo[j+1] = prev + memo[j];
          prev  = tmp;
        } else {
          prev = memo[j+1];
          memo[j+1] = memo[j];
        }
      }
    }
    return memo[s_size];
  }
};

int main () {
  Solution solution;
  string s = "rabbbit";
  string t = "rabbit";
  cout << solution.numDistinct(s,t) << endl;
}