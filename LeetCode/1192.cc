#include <vector>
#include <iostream>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> graph;
    vector<int> visited;
    vector<int> parents;
    vector<int> discovery;
    vector<int> low;
    vector<vector<int>> results{};
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph = vector<vector<int>>(n,vector<int>{});
        visited = vector<int>(n,0);
        parents = vector<int>(n,-1);
        discovery = vector<int>(n,-1);
        low = vector<int>(n,-1);

        for (auto connection : connections)
        {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }
        int node1 = 0;
        int discoveryTime = 0;
        if (graph[node1].size() > 1) {

        }
        dfs(node1, discoveryTime);
        return results;
    }
    void dfs (int node1, int& discoveryTime) {
        visited[node1] = 1;
        discovery[node1] = low[node1] = discoveryTime++;
        for (auto i = 0; i < graph[node1].size(); ++i) {
            int node2 = graph[node1][i];
            if (!visited[node2]) {
                parents[node2] = node1;
                dfs(node2, discoveryTime);
                low[node1] = min(low[node1], low[node2]);
                if (low[node2] > discovery[node1]) {
                    results.push_back(vector<int>{node1, node2});
                }
            } else if (node2 != parents[node1]) {
                low[node1] = min(low[node1], discovery[node2]);
            }
        }
    }
};

int main() {
    int n = 8;
    vector<vector<int>> connections {
        {0,1},
        {1,2},
        {2,3},
        {1,3},
        {0,4},
        {4,5},
        {5,6},
        {6,4},
        {5,7}
    };
    Solution solution;
    auto results = solution.criticalConnections(n, connections);
    for (auto pair: results) {
        cout << pair[0] << " " << pair[1] << endl;
    }
}