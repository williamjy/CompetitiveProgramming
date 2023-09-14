#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        map<int, vector<int>> costDiffToPersonIndex;
        for (auto index = 0; index < costs.size(); ++index) {
            auto costDiff = costs[index][0] - costs[index][1];
            costDiffToPersonIndex[costDiff].push_back(index);
        }
        int n = 0, result = 0;
        for (auto entry : costDiffToPersonIndex) {
            auto personIndexes = entry.second;
            for (auto index : personIndexes) {
                if (n < costs.size() / 2) {
                    result += costs[index][0];
                } else {
                    result += costs[index][1];
                }
                n++;
            }
        }
        return result;
    }
};