#include <stack>
#include <map>

using namespace std;

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
private:
    int direction = 0;
    map<int, map<int, bool>> visited;

public:
    void cleanRoom(Robot& robot)
    {
        dfs(0, 0, robot);
    }
    void dfs(const int x, const int y, Robot& robot)
    {
        if (!visited[x][y])
        {
            robot.clean();
            visited[x][y] = 1;
            for (int i = 0; i < 4; ++i)
            {
                if (robot.move())
                {
                    switch (direction)
                    {
                        case 0:
                            dfs(x - 1, y, robot);
                            break;
                        case 1:
                            dfs(x, y - 1, robot);
                            break;
                        case 2:
                            dfs(x + 1, y, robot);
                            break;
                        case 3:
                            dfs(x, y + 1, robot);
                            break;
                        default:
                            break;
                    }
                    robot.turnLeft();
                    robot.turnLeft();
                    robot.move();
                    robot.turnRight();
                }
                else
                {
                    robot.turnLeft();
                }
                direction = (direction + 1) % 4;
            }
        }
    }
};