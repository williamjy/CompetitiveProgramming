#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        vector<vector<int>> adjacentMatrix(n, vector<int>(n, 0));
        map<int, vector<int>> stopsToRoutes;
        for (auto routeIndex = 0; routeIndex < routes.size(); ++routeIndex) {
            auto route = routes[routeIndex];
            int isReachableByOneRoute = 0;
            for (auto stop : route) {
                stopsToRoutes[stop].push_back(routeIndex);
                if (stop == source || stop == target) {
                    isReachableByOneRoute++;
                }
            }
            if (isReachableByOneRoute == 1 && source == target) {
                return 0;
            } else if (isReachableByOneRoute == 2) {
                return 1;
            }
        }
        for (auto entry : stopsToRoutes) {
            auto intersectedRoutes = entry.second;
            if (intersectedRoutes.size() > 1) {
                for (auto i = 0; i < intersectedRoutes.size() - 1; ++i) {
                    for (auto j = i + 1; j < intersectedRoutes.size(); ++j) {
                        adjacentMatrix[intersectedRoutes[i]][intersectedRoutes[j]] = 1;
                        adjacentMatrix[intersectedRoutes[j]][intersectedRoutes[i]] = 1;
                    }
                }
            }
        }
        queue<int> frontQueue;
        queue<int> backQueue;
        vector<bool> visited(n, 0);
        for (auto startRoute : stopsToRoutes[source]) {
            frontQueue.push(startRoute);
        }
        int level = 1;
        while (!frontQueue.empty()) {
            while (!frontQueue.empty()) {
                auto currRoute = frontQueue.front();
                frontQueue.pop();
                if (std::find(stopsToRoutes[target].begin(), stopsToRoutes[target].end(), currRoute) != stopsToRoutes[target].end()) {
                    return level;
                }
                if (!visited[currRoute]) {
                    visited[currRoute] = true;
                    for (auto adjacentRoute = 0; adjacentRoute < adjacentMatrix[currRoute].size(); ++adjacentRoute)
                    {
                        if (adjacentMatrix[currRoute][adjacentRoute]) {
                            backQueue.push(adjacentRoute);
                        }
                    }
                }
            }
            level++;
            std::swap(frontQueue, backQueue);
        }
        return -1;
    }
};