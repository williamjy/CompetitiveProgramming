#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    return rec(n,n);
  }
  vector<string> rec(int left, int right) {
    if (left == 0) {
      vector<string> result{""};
      return result;
    }
    if (left == right) {
      vector<string> result = rec(left,right-1);
      for (auto i = result.begin(); i != result.end(); i++) {
        *i += ")";
      }
      return result;
    }
    if (right == 0) {
      vector<string> result = rec(left-1,right);
      for (auto i = result.begin(); i != result.end(); i++) {
        *i += "(";
      }
      return result;
    } else {
      vector<string> result1 = rec(left,right-1);
      for (auto i = result1.begin(); i != result1.end(); i++) {
        *i += ")";
      }
      vector<string> result2 = rec(left-1,right);
      for (auto i = result2.begin(); i != result2.end(); i++) {
        *i += "(";
      }
      result1.insert(result1.end(),result2.begin(),result2.end());
      return result1;
    }
  }
};

int main () {
  Solution solution;
  int a = 3;
  vector<string> result = solution.generateParenthesis(a);
  for (auto i : result) {
    cout << i << " ";
  }
}