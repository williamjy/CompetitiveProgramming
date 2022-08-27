#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<long long>>memo(n+1,vector<long long>(7,0));
        memo[0][0] = 1;
        for (int roll = 1; roll <= n; ++roll) {
            for (int rng = 1; rng < 7; ++rng) {
                for (int consecutive = 1; consecutive <= rollMax[rng-1] and consecutive <= roll; ++consecutive) {
                    memo[roll][rng] += memo[roll-consecutive][0];
                    memo[roll][rng] -= memo[roll-consecutive][rng];
                    memo[roll][rng] %= 1000000007;
                }
                memo[roll][0] += memo[roll][rng];
            }
        }
        return memo[n][0] % 1000000007;
    }
};

int main() {
    vector<int> rollmax{8,5,10,8,7,2};
    Solution solution;
    cout << solution.dieSimulator(20, rollmax) << endl;
}