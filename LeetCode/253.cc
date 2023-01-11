#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        map<int, int, greater<int>> endCountsOfAllRooms;
        int total = 0;
        for (auto interval : intervals) {
            for (auto iter = endCountsOfAllRooms.begin(); iter != endCountsOfAllRooms.end(); ++iter) {
                auto endOfRoomTime = iter->first;
                if (endOfRoomTime <= interval[0]) {
                    iter->second--;
                    total--;
                    if (iter->second == 0) {
                        endCountsOfAllRooms.erase(iter);
                    }
                    break;
                }
            }
            endCountsOfAllRooms[interval[1]]++;
            total++;
        }
        return total;
    }
};