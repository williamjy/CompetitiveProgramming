#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// double pointers
class Solution {
public:
  bool isSubsequence(string s, string t) {
    auto i = s.begin(), j = t.begin();
    for (;*j;i+=(*i==*j++)) {}
    return !*i;
  }
};

int main () {
  Solution solution;
  string s = "abc";
  string t = "ahbgdc";
  cout << solution.isSubsequence(s,t) << endl;
}