#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int total = 0;
        deque<int> deque_;
        for (int i = 0; i < nums.size(); ++i) {
            if (!deque_.empty() and deque_.front() < i) {
                deque_.pop_front();
            }
            if (nums[i] == deque_.size() % 2) {
                if (i + k > nums.size()) {
                    return -1;
                }
                deque_.push_back(i+k-1);
                ++total;
            }
        }
        return total;
    }
};