#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    vector<int> row1{1};
    result.push_back(row1);
    for (int i = 1; i < numRows; i++) {
      vector<int> tmp;
      for (int j = 0; j <= i; j++) {
        if (j == 0) tmp.push_back(result[i-1][j]);
        else if (j == i) tmp.push_back(result[i-1][j-1]);
        else tmp.push_back(result[i-1][j-1]+result[i-1][j]);
      }
      result.push_back(tmp);
    }
    return result;
  }
};

int main () {
  Solution s;
  int numRows = 10;
  vector<vector<int>> result = s.generate(numRows);
  for (auto i : result) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}