#include <vector>
#include <map>

using namespace std;

struct stringComparator {
    bool operator() (const string& a, const string& b) const {
        string aBeforeb = a + b;
        string bBeforea = b + a;
        if (aBeforeb == bBeforea) {
            return a.size() < b.size();
        }
        return aBeforeb > bBeforea;
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        map<string, int, stringComparator> stringSortedMap;
        string result = "";
        for (auto num : nums) {
            stringSortedMap[to_string(num)]++;
        }
        if (stringSortedMap.begin()->first == "0") {
            stringSortedMap.begin()->second = 1;
        }
        for (auto entry : stringSortedMap) {
            while (entry.second--) {
                result += entry.first;
            }
        }
        return result;
    }
};