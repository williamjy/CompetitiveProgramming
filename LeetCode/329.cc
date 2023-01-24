#include<vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> memo;

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxSize = 0;
        memo = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int row = 0; row < matrix.size(); row++) {
            for (int column = 0; column < matrix[0].size(); column++) {
                maxSize = max(maxSize, dp(matrix, row, column, -1));
            }
        }
        return maxSize;
    }
    int dp(vector<vector<int>>& matrix, int row, int column, int prev) {
        if (row < 0 || row >= matrix.size() || column < 0 || column >= matrix[0].size()) {
            return 0;
        }
        if (matrix[row][column] <= prev) {
            return 0;
        }
        if (memo[row][column]) {
            return memo[row][column];
        }
        return memo[row][column] = 1 + max({
            dp(matrix, row - 1, column, matrix[row][column]),
            dp(matrix, row + 1, column, matrix[row][column]),
            dp(matrix, row, column - 1, matrix[row][column]),
            dp(matrix, row, column + 1, matrix[row][column]),
        });
    }
};