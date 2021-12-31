#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
  vector<vector<bool>> memo;
public:
  vector<vector<string>> partition(string s) {
    memo = vector<vector<bool>> (s.size(),vector<bool>(s.size(),0));
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j <= min(i-0,(int) s.size()-i-1); j++) {
        if (!j) {
          memo[i][i] = 1;
        } else {
          memo[i-j][i+j] = memo[i-j+1][i+j-1] && s[i-j] == s[i+j];
        }
      }
    }
    for (int i = 0; i < s.size()-1; i++) {
      for (int j = 0; j <= min(i-0,(int) s.size()-i-2); j++) {
        if (!j) {
          memo[i][i+1] = s[i] == s[i+1];
        } else {
          memo[i-j][i+j+1] = memo[i-j+1][i+j] && s[i-j] == s[i+j+1];
        }
      }
    }
    for (auto a : memo) {
      for (auto b : a) {
        cout << b << " ";
      }
      cout << endl;
    }
    return rec(0,s.size(),s);
  }
  vector<vector<string>> rec(int start, int end, string s) {
    vector<vector<string>> result;
    if (start+1 == end) {
      vector<string> v{s.substr(start,1)};
      result.push_back(v);
      return result;
    }
    for (int i = start+1; i < end; i++) {
      if (memo[i][end-1]) {
        vector<vector<string>> left = rec(start,i,s);
        for (int j = 0; j < left.size(); j++) {
          left[j].push_back(s.substr(i,end-i));
        }
        result.insert(result.end(),left.begin(),left.end());
      }
    }
    if (memo[start][end-1]) result.push_back(vector<string>{s.substr(start,end-start)});
    return result;
  }
};

int main () {
  Solution solution;
  string s = "aab";
  for (auto a : solution.partition(s)) {
    for (auto b : a) {
      cout << b << " ";
    }
    cout << endl;
  }
}