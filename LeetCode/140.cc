#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
  vector<string> result;
  string stack = "";
  string s;
  vector<string> wordDict;
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    this->s = s;
    this->wordDict = wordDict;
    rec(0);
    return result;
  }
  void rec(int start) {
    if (start == s.size()) {
      result.push_back(stack.substr(0,stack.size()-1));
    }
    for (int i = start+1; i <= s.size(); i++) {
      if (find(wordDict.begin(),wordDict.end(),s.substr(start,i-start)) != wordDict.end()) {
        stack += s.substr(start,i-start);
        stack += " ";
        rec(i);
        stack = stack.substr(0,stack.size()-i+start-1);
      }
    }
  }
};

int main () {
  Solution solution;
  string s = "pineapplepenapple";
  vector<string> wordDict{
    "apple","pen","applepen","pine","pineapple"
  };
  for (auto a : solution.wordBreak(s,wordDict)) {
    cout << a << endl;
  }
}