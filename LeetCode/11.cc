#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int left = 0;
        int right = height.size()-1;
        while (left != right) {
            int lower = height[left] < height[right] ? height[left++] : height[right--];
            max = max > lower *(right-left+1) ? max : lower *(right-left+1);
        }
        return max;
    }
};

int main () {
    vector<int> v{
        1,8,6,2,5,4,8,3,7
    };
    Solution solution;
    cout << solution.maxArea(v) << endl;
}