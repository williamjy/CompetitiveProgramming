#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    int parts = s.size() / (2*numRows-2);
    string result = "";
    if (s.size() % (2*numRows-2) != 0) parts++;
    for (int i = 0, width = 2*numRows-2; i < numRows; i++, width-=2) {
      for (int p = 0; p < parts; p++) {
        if (i == 0 || i == numRows-1) {
          if (p*(2*numRows-2)+i < s.size()) result += s[p*(2*numRows-2)+i];
        } else {
          if (p*(2*numRows-2)+i < s.size()) result += s[p*(2*numRows-2)+i];
          if (p*(2*numRows-2)+i+width < s.size()) result += s[p*(2*numRows-2)+i+width];
        }
      }
      cout << endl;
    }
    return result;
  }
};

int main () {
  Solution solution;
  cout << solution.convert("PAYPALISHIRING",4) << endl;
}