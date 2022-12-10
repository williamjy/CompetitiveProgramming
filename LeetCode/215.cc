#include <set>
#include <map>
#include <vector>

using namespace std;
class Solution {
public:
    struct map_cmp {
        bool operator() (const int &a, const int &b) const {
            return a > b;
        }
    };
    int findKthLargest(vector<int>& nums, int k) {
        map<int,int,map_cmp> frequencies;
        for (auto num : nums) {
            ++frequencies[num];
        }
        for (auto p : frequencies) {
            k -= p.second;
            if (k <= 0) {
                return p.first;
            }
        }
        return 0;
    }
};