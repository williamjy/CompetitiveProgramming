#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> countsInWindow;
        vector<int> results;
        for (int position = 0; position < k; position++) {
            int number = nums[position];
            countsInWindow[number]++;
        }
        results.push_back(countsInWindow.rbegin()->first);
        for (int position = k; position < nums.size(); position++) {
            int numberToRemove = nums[position - k];
            int number = nums[position];
            countsInWindow[numberToRemove]--;
            if (countsInWindow[numberToRemove] == 0) {
                countsInWindow.erase(numberToRemove);
            }
            countsInWindow[number]++;
            int a = countsInWindow.size();
            results.push_back(countsInWindow.rbegin()->first);
        }
        return results;
    }
};