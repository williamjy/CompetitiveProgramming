#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
      return rec(s,p);
    }
    bool rec(string s, string p) {
      int s_size = s.size(), p_size = p.size();
      if (s_size == 0 && p_size == 0) return true;
      else if ((s_size == 0 || p_size == 0) && p.back() != '*') return false;
      bool result = false;
      if (s.back() == p.back() || p.back() == '.') {
        result |= rec(s.substr(0,s_size-1),p.substr(0,p_size-1));
      } else if (p.back() == '*') {
        result |= rec(s,p.substr(0,p_size-2));
        char s_last = s.back();
        char p_last = *(p.end()-2);
        if (s_last == p_last || p_last == '.') {
          for (int i = s_size - 1; i >= 0; i--) {
            if (s_last != s.at(i) && p_last != '.') break;
            result |= rec(s.substr(0,i),p.substr(0,p_size-2));
          }
        }
      } else {
        return false;
      }
      return result;
    }
};

int main () {
  Solution solution;
  string s = "aab";
  string p = "c*a*b";
  cout << solution.isMatch(s,p) << endl;

}