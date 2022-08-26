#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<vector<long>>> memo(n,vector<vector<long>>(7, vector<long>(15,0)));
        return dp(n, 0, 1, rollMax, memo);
    }
    long dp (int n, int prev_rng, int times, vector<int>& rollMax, vector<vector<vector<long>>>& memo) {
        // rng 0 is invalid, should be frm 1 to 6
        if (n == 0) {
            return 1;
        }
        if (memo[n-1][prev_rng][times-1] > 0) {
            return memo[n-1][prev_rng][times-1];
        }
        for (int rng = 1; rng < 7; ++rng) {
            if (prev_rng == rng) {
                if (times == rollMax[rng-1]) {
                    continue;
                } else {
                    memo[n-1][prev_rng][times-1] += dp(n-1, rng, times+1, rollMax, memo) % 1000000007;
                }
            } else {
                memo[n-1][prev_rng][times-1] += dp(n-1, rng, 1, rollMax, memo) % 1000000007;
            }
        }
        auto total = memo[n-1][prev_rng][times-1];
        return memo[n-1][prev_rng][times-1] % 1000000007;
    }
};

int main() {
    vector<int> rollmax{1,1,1,1,1,1};
    Solution solution;
    cout << solution.dieSimulator(2, rollmax) << endl;
}