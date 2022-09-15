#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int,vector<vector<int>>> dist_map;
        for (auto point : points) {
            auto dist = point[0]*point[0]+point[1]*point[1];
            dist_map[dist].push_back(point);
        }
        vector<vector<int>> results;
        for (auto dist_iter = dist_map.begin(); dist_iter != dist_map.end() && k > 0; ++dist_iter) {
            for (auto point_iter = dist_iter->second.begin(); point_iter != dist_iter->second.end() && k > 0; ++point_iter,--k) {
                results.push_back(*point_iter);
            }
        }
        return results;
    }
};