#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int result = 0;
    for (auto i = prices.begin()+1; i != prices.end(); i++) {
      result += (*i - *(i-1) > 0) ? *i - *(i-1) : 0;
    }
    return result;
  }
};

int main () {
  Solution solution;
  vector<int> triangle{1,2,3,4,5,6};
  cout << solution.maxProfit(triangle) << endl;
}