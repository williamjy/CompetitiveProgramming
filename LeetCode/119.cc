#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    int row[34] = {0};
    row[0]=1;
    for (int i = 1; i <= rowIndex; i++) {
      for (int j = i; j >= 1; j--) {
        row[j] = row[j-1] + row[j];
      }
    }
    vector<int> result;
    for (int i = 0; i <= rowIndex; i++) {
      result.push_back(row[i]);
    }
    return result;
  }
};

int main () {
  Solution s;
  int v = 4;
  vector<int> result = s.getRow(v);
  for (auto i : result) {
    cout << i << " ";
  }
}