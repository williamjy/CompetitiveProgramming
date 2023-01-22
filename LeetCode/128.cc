#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        unordered_map <int, int> startToEnd;
        unordered_map<int, int> endToStart;
        for (auto num : nums) {
            if (startToEnd.find(num) != startToEnd.end() || endToStart.find(num) != endToStart.end()) {
                continue;
            }
            bool canNumFitToStart = (startToEnd.find(num + 1) != startToEnd.end());
            bool canNumFitToEnd = (endToStart.find(num - 1) != endToStart.end());
            if (canNumFitToStart && canNumFitToEnd) {
                int newEnd = startToEnd[num + 1];
                int newStart = endToStart[num - 1];
                startToEnd.erase(num+1);
                endToStart.erase(num-1);
                startToEnd[newStart] = newEnd;
                endToStart[newEnd] = newStart;
            } else if (canNumFitToStart) {
                int end = startToEnd[num + 1];
                startToEnd[num] = end;
                startToEnd.erase(num + 1);
                endToStart[end] = num;
            } else if (canNumFitToEnd) {
                int start = endToStart[num - 1];
                endToStart[num] = start;
                endToStart.erase(num - 1);
                startToEnd[start] = num;
            } else {
                startToEnd[num] = num;
                endToStart[num] = num;
            }
        }
        int result = 0;
        for (auto p : startToEnd) {
            result = max(result, p.second - p.first);
        }
        return result+1;
    }
};