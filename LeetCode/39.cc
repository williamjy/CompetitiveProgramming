#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<int>> answers;
    vector<int> current;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return answers;
    }
    void dfs (vector<int>& candidates, int target, int position) {
        if (target == 0) {
            answers.push_back(current);
            return;
        }
        if (target < -1) {
            return;
        }
        if (position == candidates.size()) {
            return;
        }
        for (int count = 1; count <= target / candidates[position]; ++count) {
            current.push_back(candidates[position]);
            dfs(candidates, target - count * candidates[position], position+1);
        }
        for (int count = 1; count <= target / candidates[position]; ++count) {
            current.pop_back();
        }
        dfs(candidates, target, position+1);
    }
};

int main() {
    Solution solution;
    int target = 7;
    vector<int> candidates{
        2,3,6,7
    };
    solution.combinationSum(candidates, 7);
}