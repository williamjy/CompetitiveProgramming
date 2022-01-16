#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

// O(nlogn)
// https://www.cs.princeton.edu/courses/archive/spring13/cos423/lectures/LongestIncreasingSubsequence.pdf
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> piles {10000};
    for (int i = 0; i < nums.size(); i++) {
      int start = 0, end = piles.size();
      while (start < end) {
        int mid = (start+end)/2;
        if (nums[i] <= piles[mid]) end = mid;
        else start = mid + 1;
      }
      if (piles.size() == start) piles.push_back(nums[i]);
      else piles[start] = nums[i];
    }
    return piles.size();
  }
};

int main () {
  Solution solution;
  vector<int> nums{
    1,10,7,7,7,7,7,7,9
  };
  cout << solution.lengthOfLIS(nums) << endl;
}