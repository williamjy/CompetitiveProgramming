#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

// Timeout solution

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results{};
        if (nums.size() < 4) return results;
        sort(nums.begin(),nums.end());
        int a, b, c, d;
        for (a = 0; a < nums.size()-3; a++) {
            if (!a || nums[a] != nums[a-1]) {
                for (b = a+1; b < nums.size()-2; b++) {
                    if (b == a+1 || nums[b] != nums[b-1]) {
                        int sumForCD = target - nums[a] - nums[b];
                        c = b+1, d = nums.size()-1;
                        while (c < d) {
                            if (nums[c] + nums[d] == sumForCD) {
                                results.push_back(vector<int>{nums[a],nums[b],nums[c],nums[d]});
                                while (c < nums.size()-2 && nums[c] == nums[c+1] ) {
                                    c++;
                                }
                                c++;
                            } else if (nums[c] + nums[d] < sumForCD) {
                                c++;
                            } else {
                                d--;
                            }
                        }
                    }
                }
            }
        }
        return results;
    }
};

int main () {
    Solution solution;
    vector<int> nums{
        -2,-1,0,0,1,2
    };
    auto s = solution.fourSum(nums,0);
    for (auto i : s) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}