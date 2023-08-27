#include <vector>

using namespace std;

class Solution {
private:    
    int row = 0;
    int column = 0;
    vector<vector<bool>> visited;
    vector<int> directionWestEast{-1,1};

public:
    int countBattleships(vector<vector<char>>& board)
    {
        row = board.size(), column = board[0].size();
        visited = vector<vector<bool>>(row, vector<bool>(column, false));
        int count = 0;
        for (int m = 0; m < row; ++m)
        {
            for (int n = 0; n < column; ++n)
            {
                if (!visited[m][n] && board[m][n] == 'X')
                {
                    // Search vertical direction first
                    count += dps(m, n, 0, board);
                    // Then we search horizontal direction
                    visited[m][n] = false;
                    count += dps(m, n, 1, board);
                    // -1 because the battleship is count twice
                    count--;
                }
            }
        }
        return count;
    }
    
    int dps(const int m, const int n, bool direction, vector<vector<char>>& board)
    {
        if (m >= row || m < 0 || n >= column || n < 0 || visited[m][n])
        {
            return 0;
        }
        visited[m][n] = true;
        int isBattleShip = (board[m][n] == 'X');
        if (isBattleShip)
        {
            if (direction)
            {
                dps(m - 1, n, direction, board);
                dps(m + 1, n, direction, board);
            }
            else
            {
                dps(m, n - 1, direction, board);
                dps(m, n + 1, direction, board);
            }
        }
        return isBattleShip;
    }
};