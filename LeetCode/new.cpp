#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    cout << rec(nums) << endl;
    return nums.at(4);
  }
  int rec (vector<int>& nums) {
    return nums.at(3);
  }
};

int main () {
  vector<int> v{1,2,3,4,5};
  cout << v.size() << endl;
  v.erase(v.begin(),v.begin()+1);
  cout << v.size() << endl;
  for (auto i : v) cout << i << " ";
  cout << endl;
}