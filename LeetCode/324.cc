#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        auto tmp = nums;
        sort(tmp.begin(),tmp.end());
        int mid = (nums.size()-1)/2;
        for (int i = mid; i >=0; --i) {
            nums[(mid-i)*2] = tmp[i];
        }
        for (int i = nums.size()-1; i > mid; --i) {
            nums[(nums.size()-i)*2-1] = tmp[i];
        }
    }
};

int main() {
    vector<int> v{
        4,5,5,6
    };
    Solution solution;
    solution.wiggleSort(v);
    for (auto i : v) {
        cout << i << " ";
    };
}