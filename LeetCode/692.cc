#include <map>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    struct set_cmp {
        bool operator() (const pair<int,string>& left, const pair<int,string>& right) const {
            return left.first == right.first ? left.second < right.second : left.first > right.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        set<pair<int,string>,set_cmp> topKSet;
        map<string,int> freqMap;
        for (auto word : words) {
            freqMap[word]++;
        }
        for (auto pr : freqMap) {
            topKSet.insert(make_pair(pr.second,pr.first));
            if (topKSet.size() > k) {
                topKSet.erase(prev(topKSet.end()));
            }
        }
        vector<string> results;
        for (auto p : topKSet) {
            results.push_back(p.second);
        }
        return results;
    }
};