#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] == b[0] ? a[1] < b[1] : (a[0] < b[0]);
        });
        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals.front());
        for (auto interval : intervals) {
            if (interval[0] <= mergedIntervals.back().back()) {
                if (interval[1] > mergedIntervals.back().back()) {
                    mergedIntervals.back().back() = interval[1];
                }
            } else {
                mergedIntervals.push_back(vector<int>{interval[0], interval[1]});
            }
        }
        return mergedIntervals;
    }
};