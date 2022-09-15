#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    struct point_cmp {
        bool operator() (const vector<int> & left, const vector<int> & right) {
            return left[0]*left[0] + left[1]*left[1] < right[0]*right[0] + right[1]*right[1];
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto kth = points.begin() + k;
        nth_element(points.begin(),kth,points.end(),point_cmp());
        return {points.begin(),points.begin()+k};
    }
};

int main() {
    vector<vector<int>> points {
        {1,3},
        {-2,4},
        {3,3}
    };
    Solution solution;
    auto results = solution.kClosest(points, 3);
    for (auto i : results) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}