#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    rec(result,"",n,n);
    return result;
  }
  void rec(vector<string> &ls, string str, int left, int right) {
    if (right == 0) ls.push_back(str);
    else if (left == 0) rec(ls,str+")",left,right-1);
    else if (left == right) rec(ls,str+"(",left-1,right);
    else {
      rec(ls,str+")",left,right-1);
      rec(ls,str+"(",left-1,right);
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