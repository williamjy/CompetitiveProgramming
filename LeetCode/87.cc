#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

class Solution {
private:
  map<string,bool> memo;
public:
  bool isScramble(string s1, string s2) {
    if(memo.find(s1+s2)!=memo.end()) return memo[s1+s2];
    if (s1 == s2) {
      return memo[s1+s2] = true;
    }
    int letters[128] = {0};
    for(char c:s1)
      letters[c] ++;
    for(char c:s2) {
      letters[c] --;
      if(letters[c] < 0) return memo[s1+s2] = false;
    }
    for (int i = 1; i < s1.size(); i++) {
      if (isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i))) {
        return memo[s1+s2]=true;
      }
      if (isScramble(s1.substr(0,i),s2.substr(s2.size()-i)) && isScramble(s1.substr(i),s2.substr(0,s2.size()-i))) {
        return memo[s1+s2]=true;
      }
    }
    return memo[s1+s2]=false;
  }
};

int main () {
  Solution solution;
  string s1 = "abcdd";
  string s2 = "dbdac";
  cout << solution.isScramble(s1,s2) << endl;
}