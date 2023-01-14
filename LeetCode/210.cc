#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacent(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for (auto p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];
            adjacent[prerequisite].push_back(course);
            indegree[course]++;
        }
        vector<int> pushed(numCourses, 0);
        vector<int> result;
        int loop = 0;
        while (loop++ < numCourses) {
            for (int course = 0; course < numCourses; course++) {
                if (indegree[course] == 0 and !pushed[course]) {
                    result.push_back(course);
                    pushed[course] = 1;
                    for (auto c : adjacent[course]) {
                        indegree[c]--;
                    }
                }
            }
        }
        return result.size() == numCourses ? result : vector<int>();
    }
};

