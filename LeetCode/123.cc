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
    int hold1 = -10000, hold2 = -10000;
    int release1 = 0, release2 = 0;
    for(int i:prices){
        release2 = max(release2, hold2+i);
        hold2    = max(hold2,    release1-i);
        release1 = max(release1, hold1+i);
        hold1    = max(hold1,    -i);
        // cout << "i: " << i << ", hold1: " << hold1 << ", release1: " << release1
        //   << ", hold2: " << hold2 << ", release2: " << release2 << endl;
    }
    return release2;
  }
};

int main () {
  Solution solution;
  vector<int> triangle{1,3,2,5,3,7,4,9};
  cout << solution.maxProfit(triangle) << endl;
}