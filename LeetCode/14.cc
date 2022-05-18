#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    int i = 0;
    while (1) {
      bool common = i < strs[0].size();
      char curr = strs[0][i];
      for (auto j : strs) {
        if (i >= j.size() || curr != j[i]) {
          common = false;
          break;
        }
      }
      if (common == false) break;
      i++;
    }
    return strs[0].substr(0,i);
  }
};

int main () {
  Solution solution;
  vector<string> strs{
    "flower","flow","flight"
  };
  cout << solution.longestCommonPrefix(strs) << endl;
}