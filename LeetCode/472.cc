#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string& left, const string& right) {
            return left.size() == right.size() ? left < right : left.size() < right.size();
        });
        vector<vector<bool>> dp;
        for (auto word : words) {
            vector<bool> tmp(word.size()+1,0);
            tmp[0] = true;
            dp.push_back(tmp);
        }
        set<string> previous;
        vector<string> results;
        for (int index = 0; index < words.size(); index++) {
            auto curr_word = words[index];
            for (int end = 1; end <= curr_word.size(); end++) {
                for (int break_point = 0; break_point < end; break_point++) {
                    auto word2 = curr_word.substr(break_point,end-break_point);
                    if (dp[index][break_point] && previous.find(word2) != previous.end()) {
                        dp[index][end] = dp[index][break_point];
                        break;
                    }
                }
            }
            previous.insert(curr_word);
            if (dp[index][curr_word.size()]) {
                results.push_back(curr_word);
            }
        }
        return results;
    }
};