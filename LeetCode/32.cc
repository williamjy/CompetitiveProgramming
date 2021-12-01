#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// class Solution {
// public:
//   int longestValidParentheses(string s) {
//     int n = s.size();
//     vector<bool> memo(n,true);
//     int x = 0;
//     for (int l = 2; l <= n; l += 2) {
//       for (int i = 0; i <= n-l; i++) {
//         memo[i] = (s[i] == '(' && s[i+l-1] == ')' && memo[i+1]) 
//           || (s[i] == '(' && s[i+1] == ')' && memo[i+2]) 
//           || (s[i+l-2] == '(' && s[i+l-1] == ')' && memo[i]);
//         if (memo[i]) x = l;
//       }
//       for (auto i : memo) cout << i << " ";
//       cout << endl;
//     }
//     return x;
//   }
// };

// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         stack<int> stk;
//         stk.push(-1);
//         int maxL=0;
//         for(int i=0;i<s.size();i++)
//         {
//             int t=stk.top();
//             if(t!=-1&&s[i]==')'&&s[t]=='(')
//             {
//                 stk.pop();
//                 maxL=max(maxL,i-stk.top());
//             }
//             else
//                 stk.push(i);
//         }
//         return maxL;
//     }
// };

class Solution {
public:
  int longestValidParentheses(string s) {
    int n = s.size();
    if (!n) return n;
    stack<int> stack;
    vector<int> memo(n+1,0);
    int max = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') stack.push(i);
      else {
       if (!stack.empty()) {
         int p = stack.top();
         stack.pop();
         memo[i+1] = memo[p]+i-p+1;
       }
      }
      max = (max > memo[i+1]) ? max : memo[i+1];
    }
    return (max > memo[n]) ? max : memo[n];
  }
};

int main () {
  Solution solution;
  string s = "(()))";
  cout << solution.longestValidParentheses(s) << endl;

}