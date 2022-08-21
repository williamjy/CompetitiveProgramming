#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int tmp1 = 0, tmp2 = 0, tmp3;
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j <= (n-1)/2; ++j) {
                for (int cnt = 0; cnt < 4; ++cnt) {
                    tmp1 = matrix[i][j];
                    matrix[i][j] = tmp2;
                    tmp2 = tmp1;
                    tmp3 = i;
                    i = j;
                    j = tmp3;
                    j = n - j -1;
                }
                matrix[i][j] = tmp2;
            }
        }
    }
};

int main () {
    vector<vector<int>> matrix {
    {1,2,3},
    {4,5,6},
    {7,8,9},
    };
    Solution solution;
    solution.rotate(matrix);
}