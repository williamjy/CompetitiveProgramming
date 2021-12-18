#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// dp
class Solution {
public:
  bool isSubsequence(string s, string t) {
    int size_s = s.size(), size_t = t.size();
    if (!size_s) return 1;
    if (!size_t) return 0;
    vector<int> memo(size_t+1,1);
    for (int i = 1; i <= size_s; i++) {
      int prev = memo[0];
      memo[0] = 0;
      for (int j = 1; j <= size_t; j++) {
        if (s[i-1] == t[j-1]) {
          memo[j] ^= prev;
          prev ^= memo[j];
          memo[j] ^= prev;
        } else {
          prev = memo[j];
          memo[j] = memo[j-1];
        }
      }
      for (auto i : memo) cout << i << " ";
      cout << endl;
    }
    return memo[size_t];
  }
};

int main () {
  Solution solution;
  string s = "abc";
  string t = "ahbgdc";
  cout << solution.isSubsequence(s,t) << endl;
}