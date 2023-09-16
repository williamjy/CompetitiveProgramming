#include <vector>
#include <map>
#include <algorithm>

using namespace std;


// Calculate all connected components
// First check the component with 1 infected node only, return the node in the largest component,
// If all components have more than 1 infected nodes, return the smallest node in the component
class Solution {
private:
    vector<int> m_InfectedNodes;
    vector<int> m_CurrComponent;
    map<int, vector<int>, std::greater<int>> m_SizeOfComponentWithOneInfectedNodesToInfectedNodes;
    vector<bool> visited;

public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        std::sort(initial.begin(), initial.end());
        auto n = graph.size();
        visited = vector<bool>(n, false);
        for (auto infectedNode : initial) {
            m_InfectedNodes.clear();
            m_CurrComponent.clear();
            dfs(infectedNode, graph, initial);
            if (m_InfectedNodes.size() == 1) {
                m_SizeOfComponentWithOneInfectedNodesToInfectedNodes[m_CurrComponent.size()].push_back(m_InfectedNodes[0]);
            }
        }
        if (!m_SizeOfComponentWithOneInfectedNodesToInfectedNodes.empty()) {
            auto tmp = m_SizeOfComponentWithOneInfectedNodesToInfectedNodes.begin()->second;
            std::sort(tmp.begin(), tmp.end());
            return tmp[0];
        }
        return initial[0];
    }

    void dfs(const int node, const vector<vector<int>>& graph, const vector<int>& initial) {
        if (!visited[node]) {
            visited[node] = true;
            if (std::find(initial.begin(), initial.end(), node) != initial.end()) {
                m_InfectedNodes.push_back(node);
            }
            m_CurrComponent.push_back(node);
            for (auto nextNode = 0; nextNode < graph[node].size(); ++nextNode) {
                if (!visited[nextNode] && graph[node][nextNode]) {
                    dfs(nextNode, graph, initial);
                }
            }
        }
    }
};