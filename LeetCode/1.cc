#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> map;
    for (int i = 0; i < nums.size(); i++) {
      if (map.count(target-nums[i])) return {map[target-nums[i]],i};
      map[nums[i]] = i;
    }
      return {};
  }
};

int main () {
  Solution solution;
  vector<int> nums{2,7,11,15};
  vector<int> result = solution.twoSum(nums,9);
  for (auto i : result) cout << i << " ";
  cout << endl;
}