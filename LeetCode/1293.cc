#include <vector>
#include <queue>

using namespace std;

#define UNAVAILABLE 1600

struct QueueEntry
{
    int m;
    int n;
    int steps;
    int elimatedBlocks;
    QueueEntry(int _m, int _n, int _steps, int _elimatedBlocks) : m(_m), n(_n), steps(_steps), elimatedBlocks(_elimatedBlocks)
    {
    }
};


class Solution {
private:
    vector<int> m_directions{-1, 1};

public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int column = grid[0].size();
        vector<vector<int>> minElimatedToLocation(row, vector<int>(column, UNAVAILABLE));
        vector<vector<int>> stepsToLocation(row, vector<int>(column, UNAVAILABLE));
        vector<vector<int>> minSteps(row, vector<int>(column, UNAVAILABLE));
        queue<QueueEntry> bfsQueue;
        bfsQueue.push(QueueEntry(0, 0, 0, 0));
        while (!bfsQueue.empty())
        {
            const auto currentEntry = bfsQueue.front();
            bfsQueue.pop();
            const auto m = currentEntry.m;
            const auto n = currentEntry.n;
            const auto steps = currentEntry.steps;
            const auto elimatedBlocks = currentEntry.elimatedBlocks;
            if (elimatedBlocks <= k && (elimatedBlocks < minElimatedToLocation[m][n] || steps < stepsToLocation[m][n]))
            {
                if (elimatedBlocks < minElimatedToLocation[m][n])
                {
                    minElimatedToLocation[m][n] = elimatedBlocks;
                    stepsToLocation[m][n] = steps;
                }
                minSteps[m][n] = minSteps[m][n] < steps ? minSteps[m][n] : steps;
                for (auto verticalDirection : m_directions)
                {
                    if (m + verticalDirection >= 0 && m + verticalDirection < row)
                    {
                        const auto isCellBlocked = grid[m + verticalDirection][n];
                        if (elimatedBlocks < k || (elimatedBlocks == k && !isCellBlocked))
                        {
                            bfsQueue.push(QueueEntry(m + verticalDirection, n, steps + 1, elimatedBlocks + grid[m + verticalDirection][n]));
                        }
                    }
                }
                for (auto horizontalDirection : m_directions)
                {
                    if (n + horizontalDirection >= 0 && n + horizontalDirection < column)
                    {
                        const auto isCellBlocked = grid[m][n + horizontalDirection];
                        if (elimatedBlocks < k || (elimatedBlocks == k && !isCellBlocked))
                        {
                            bfsQueue.push(QueueEntry(m, n + horizontalDirection, steps + 1, elimatedBlocks + grid[m][n + horizontalDirection]));
                        }
                    }
                }
            }
        }
        return (minSteps[row - 1][column - 1] == UNAVAILABLE) ? -1 : minSteps[row - 1][column - 1];
    }
};