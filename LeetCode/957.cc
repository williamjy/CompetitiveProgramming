#include <set>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> curr = cells;
        vector<vector<int>> states;
        bool found = false;
        for (int i = 0; i < n; i++) {
            curr[0] = 0;
            curr[7] = 0;
            for (int i = 1; i < 7; ++i) {
                if (cells[i-1] == cells[i+1]) {
                    curr[i] = 1;
                } else {
                    curr[i] = 0;
                }
            }
            if (!states.empty() && states[0] == curr) {
                found = true;
                break;
            }
            states.push_back(curr);
            swap(cells,curr);
        }
        if (found) {
            return states[(n-1) % states.size()];
        }
        return cells;
    }
};