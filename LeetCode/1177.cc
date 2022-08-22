#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> results;
        vector<vector<bool>> queryMatrix;
        vector<bool> curr(26,0);
        queryMatrix.push_back(curr);
        for (int i = 0; i < s.size(); ++i) {
            curr[s[i]-'a'] = !curr[s[i]-'a'];
            queryMatrix.push_back(curr);
        }
        for (auto query : queries) {
            int total = 0;
            for (int i = 0; i < 26; ++i) {
                total += (queryMatrix[query[0]][i] ^ queryMatrix[query[1]+1][i]);
            }
            results.push_back(total/2 <= query[2]);
        }
        return results;
    }
};

int main() {
    string s = "hunu";
    vector<vector<int>> vec{
        {0,3,1}
    };
    Solution solution;
    auto results = solution.canMakePaliQueries(s, vec);
    for (auto r : results) {
        cout << r << endl;
    }
}