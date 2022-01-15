#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> diffWaysToCompute(string expression) {
    vector<int> result;
    for (int i = 0; i < expression.size(); i++) {
      if (ispunct(expression[i])) {
        vector<int> left = diffWaysToCompute(expression.substr(0,i));
        vector<int> right = diffWaysToCompute(expression.substr(i+1));
        if (expression[i] == '+') {
          for (auto j : left) {
            for (auto k :right) {
              result.push_back(j+k);
            }
          }
        } else if (expression[i] == '-') {
          for (auto j : left) {
            for (auto k :right) {
              result.push_back(j-k);
            }
          }
        } else if (expression[i] == '*') {
          for (auto j : left) {
            for (auto k :right) {
              result.push_back(j*k);
            }
          }
        }
      }
    }
    if (!result.size()) result.push_back(stoi(expression));
    return result;
  }
};

int main () {
  Solution solution;
  string expression = "11-1-1";
  vector<int> ways = solution.diffWaysToCompute(expression);
  for (auto i : ways) cout << i << " ";
  cout << endl;
}