#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int result = -10, product = 1, lastNegativeProduct = 1;
    bool renew = 1;
    for (auto i : nums) {
      if (i == 0) {
        result = result > 0 ? result : 0;
        product = 1;
        lastNegativeProduct = 1;
        renew = 1;
      } else {
        product *= i;
        result = result > product ? result : product;
        if (product < 0) {
          result = result > product / lastNegativeProduct ? result : product / lastNegativeProduct;
          if (renew) {
            lastNegativeProduct = product;
            renew = 0;
          }
        }
      }
    }
    return result;
  }
};

int main () {
  Solution solution;
  vector<int> nums {
    3,-1,4
  };
  cout << solution.maxProduct(nums) << endl;
}