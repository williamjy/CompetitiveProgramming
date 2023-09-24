#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int pathSum(vector<int>& nums) {
        map<int, map<int, int>> nodes;
        for (auto depth = 0; depth < 4; ++depth) {
            for (auto position = 0; position < 8; ++position) {
                nodes[depth][position] = -1;
            }
        }
        for (auto num : nums)
        {
            int digit = num % 10;
            num /= 10;
            int position = num % 10;
            num /= 10;
            int depth = num % 10;
            nodes[depth - 1][position - 1] = digit;
        }
        int currPathSum = 0;
        int depth = 0;
        int position = 0;
        int result = 0;
        dfs(currPathSum, depth, position, result, nodes);
        return result;
    }
    void dfs(int& currPathSum, int& depth, int& position, int& result, map<int, map<int, int>>& nodes) {
        if (nodes[depth][position] == -1) {
            return;
        }
        currPathSum += nodes[depth][position];
        if ((depth == 3) || (nodes[depth + 1][position * 2] == -1 && nodes[depth + 1][position * 2 + 1] == -1)) {
            result += currPathSum;
            currPathSum -= nodes[depth][position];
            return;
        }
        depth++;
        position *= 2;
        dfs(currPathSum, depth, position, result, nodes);
        position++;
        dfs(currPathSum, depth, position, result, nodes);
        position--;
        position /= 2;
        depth--;
        currPathSum -= nodes[depth][position];
        return;
    }
};