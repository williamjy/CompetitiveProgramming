#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() == 1) return 0;
    int min = 10000;
    int result = 0;
    for (auto i : prices) {
      result = result > (i - min) ? result : i - min;
      min = (min < i) ? min : i;
    }
    return result;
  }
};

int main () {
  Solution solution;
  vector<int> triangle{7,1,5,3,6,4};
  cout << solution.maxProfit(triangle) << endl;
}