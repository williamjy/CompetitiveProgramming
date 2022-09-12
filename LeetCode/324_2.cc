#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto m = nums.begin() + n/2;
        nth_element(nums.begin(),m,nums.end());
        int median = *m;

        int i = 0, j = 0, k = n-1;

        #define v(i) nums[(1+2*i)%(n|1)]

        while (j <= k) {
            if  (v(j) > median) {
                swap(v(j),v(i));
                ++i;
                ++j;
            } else if (v(j) == median) {
                ++j;
            } else {
                swap(v(j),v(k));
                --k;
            }
        }
    }
};

int main() {
    vector<int> v{
        4,5,5,6,7,7,7,7,
    };
    Solution solution;
    solution.wiggleSort(v);
    for (auto i : v) {
        cout << i << " ";
    };
}