#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> endList (26,-1);
        for (int i = 0; i < s.size(); ++i) {
            endList[s[i]-'a'] = i;
        }
        int i = 0;
        vector<int> parts;
        while (i < s.size()) {
            int end = endList[s[i]-'a'];
            for (int j = i+1; j < end; ++j) {
                auto possibleEnd = endList[s[j]-'a'];
                end = end > possibleEnd ? end : possibleEnd;
            }
            parts.push_back(end-i+1);
            i = end+1;
        }
        return parts;
    }
};