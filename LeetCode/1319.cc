#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) {
            return -1; 
        }
        int connectedComponent = 0;
        vector<vector<int>> edges_(n, vector<int>());
        vector<bool> visited_(n,0);
        stack<int> stack_;
        stack_.push(0);
        for (auto connection: connections) {
            edges_[connection[0]].push_back(connection[1]);
            edges_[connection[1]].push_back(connection[0]);
        }
        for (int node = 0; node < n; ++node) {
            if (!visited_[node]) {
                dfs(edges_, visited_, node);
                connectedComponent++;
            }
        }
        return connectedComponent-1;
    }
    void dfs (vector<vector<int>>& edges_, vector<bool>& visited_, int node) {
        if (!visited_[node]) {
            visited_[node] = 1;
            for (auto next : edges_[node]) {
                dfs(edges_, visited_, next);
            }
        }
    }
};