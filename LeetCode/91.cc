#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    vector<int> memo(s.size()+1,0);
    if (s[0] == '0') return 0;
    int memo1 = 1, memo2 = 1, prev = 0, curr = 0;
    for (int i = 1; i < s.size(); i++) {
      prev = s[i-1] - '0';
      curr = s[i] - '0';
      if ((prev == 0 || prev > 2) && curr == 0) {
        // curr = 0
        return 0;
      } else if (prev == 0 && curr > 0) {
        memo1 = memo2;
      } else if (prev < 3 && curr == 0) {
        // 10 or 20
        memo1 ^= memo2;
        memo2 ^= memo1;
        memo1 ^= memo2;
      } else if ((prev) * 10 + curr <= 26) {
        // is a letter
        memo1 += memo2;
        memo1 ^= memo2;
        memo2 ^= memo1;
        memo1 ^= memo2;
      } else {
        // 01 02 03 35 34 67
        memo1 = memo2;
      }
    }
    return memo2;
  }
};

// class Solution {
// public:
//   int numDecodings(string s) {
//     vector<int> memo(s.size()+1,0);
//     if (s[0] == '0') return 0;
//     int memo1 = 1, memo2 = 1, memo3 = 1;
//     int letter = 0;
//     for (int i = 1; i < s.size(); i++) {
//       if ((s[i-1] - '0' == 0 || s[i-1] - '0' > 2) && s[i] - '0' == 0) {
//         return 0;
//       } else if (s[i-1] - '0' == 0 && s[i] - '0' > 0) {
//         memo3 = memo2;
//       } else if (s[i-1] - '0' < 3 && s[i] - '0' == 0) {
//         memo3 = memo1;
//       } else if ((s[i-1] - '0') * 10 + s[i] - '0' <= 26) {
//         memo3 = memo1 + memo2;
//       } else {
//         memo3 = memo2;
//       }
//       memo1 = memo2;
//       memo2 = memo3;
//     }
//     return memo3;
//   }
// };

// class Solution {
// public:
//   int numDecodings(string s) {
//     vector<int> memo(s.size()+1,0);
//     if (s[0] == '0') return 0;
//     memo[0] = 1, memo[1] = 1;
//     int letter = 0;
//     for (int i = 2; i < memo.size(); i++) {
//       if ((s[i-2] - '0' == 0 || s[i-2] - '0' > 2) && s[i-1] - '0' == 0) {
//         return 0;
//       } else if (s[i-2] - '0' == 0 && s[i-1] - '0' > 0) {
//         memo[i] = memo[i-1];
//       } else if (s[i-2] - '0' < 3 && s[i-1] - '0' == 0) {
//         memo[i] = memo[i-2];
//       } else if ((s[i-2] - '0') * 10 + s[i-1] - '0' <= 26) {
//         memo[i] = memo[i-2] + memo[i-1];
//       } else {
//         memo[i] = memo[i-1];
//       }
//     }
//     return memo[s.size()];
//   }
// };

int main () {
  Solution solution;
  string s = "111026";
  cout << solution.numDecodings(s) << endl;
}