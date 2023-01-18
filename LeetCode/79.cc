#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), 0));
        for (int row = 0; row < board.size(); row++) {
            for (int column = 0; column < board[0].size(); column++) {
                auto isExist = dfs(row, column, 0, visited, board, word);
                if (isExist) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs (int row, int column, int letterPosition, vector<vector<bool>>& visited, vector<vector<char>>& board, string word) {
        if (letterPosition == word.size()) {
            return true;
        }
        if (row < 0 || row >= board.size() || column < 0 || column >= board[0].size()) {
            return false;
        }
        if (visited[row][column]) {
            return false;
        }
        if (board[row][column] != word[letterPosition]) {
            return false;
        }
        visited[row][column] = 1;
        bool isExit = dfs(row - 1, column, letterPosition + 1, visited, board, word) ||
            dfs(row + 1, column, letterPosition + 1, visited, board, word) ||
            dfs(row, column - 1, letterPosition + 1, visited, board, word) ||
            dfs(row, column + 1, letterPosition + 1, visited, board, word);
        visited[row][column] = 0;
        return isExit;
    }
};