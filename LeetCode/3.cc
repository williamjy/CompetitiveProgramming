#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    map<char,int> map;
    int result = 0, prev = -1;
    for (int i = 0; i < s.size(); i++) {
      if (map.count(s[i])) {
        prev = max(prev,map[s[i]]);
      }
      result = max(result,i-prev);
      map[s[i]] = i;
    }
    return result;
  }
};

int main () {
  Solution solution;
  string s = "abcd";
  cout << solution.lengthOfLongestSubstring(s) << endl;
}