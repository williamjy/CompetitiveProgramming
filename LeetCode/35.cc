#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    return rec(nums,target,0,nums.size());
  }
  int rec(vector<int>& nums, int target, int start, int end) {
    if (start >= end) return end;
    if (start + 1 == end) return nums[start] >= target ? start : end;
    int mid = (start + end) / 2;
    if (nums[mid] == target) return mid;
    else if (nums[mid] > target) return rec(nums,target,0,mid);
    else return rec(nums,target,mid,end);
  }
};

int main () {
  Solution solution;
  vector<int> nums{1,3,6};
  cout << solution.searchInsert(nums,5) << endl;
}