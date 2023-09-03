#include <vector>

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> glasses(101, vector(101, 0.0));
        glasses[0][0] += poured;
        for (auto curr_row = 0; curr_row < 100; ++curr_row)
        {
            bool isAnyPoured = false;
            for (auto curr_glass = 0; curr_glass <= curr_row; ++curr_glass)
            {
                if (glasses[curr_row][curr_glass] > 1.0)
                {
                    auto num_pour = (glasses[curr_row][curr_glass] - 1.0) / 2.0;
                    glasses[curr_row][curr_glass] = 1.0;
                    glasses[curr_row + 1][curr_glass] += num_pour;
                    glasses[curr_row + 1][curr_glass + 1] += num_pour;
                    isAnyPoured = true;
                }
            }
            if (!isAnyPoured)
            {
                break;
            }
        }
        return glasses[query_row][query_glass];
    }
};