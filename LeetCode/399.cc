#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {
private:
    map<string, map<string, double>> adjacentMatrix;
    vector<double> results;
    map<string, bool> visited;
    string source;
    string destination;
    double result = 1.0;

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        auto n = equations.size();
        for (auto i = 0; i < equations.size(); ++i) {
            auto A = equations[i][0];
            auto B = equations[i][1];
            adjacentMatrix[A][B] = values[i];
            adjacentMatrix[B][A] = 1 / values[i];
        }
        for (auto query : queries) {
            result = 1.0;
            source = query[0];
            destination = query[1];
            if (source == destination && adjacentMatrix[source].size() == 0) {
                results.push_back(-1);
            } else {
                visited.clear();
                if (!dfs(source)) {
                    results.push_back(-1);
                };
            }
        }
        return results;
    }

    bool dfs(const string& variable) {
        if (!visited[variable]) {
            visited[variable] = true;
            if (variable == destination) {
                results.push_back(result);
                return true;
            }
            for (auto entry : adjacentMatrix[variable]) {
                auto nextVariable = entry.first;
                if (!visited[nextVariable]) {
                    result *= entry.second;
                    if(dfs(nextVariable)) {
                        return true;
                    }
                    result /= entry.second;
                }
            }
        }
        return false;
    }
};