#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        map<int, map<string,int>> wordBySize;
        for (auto word : words) {
            wordBySize[word.size()].emplace(word, 1);
        }
        // dp
        int longest = 1;
        for (int i = 1; i <= 16; ++i) {
            auto shortWords = wordBySize[i-1];
            auto longWords = wordBySize[i];
            for (auto longWord : longWords) {
                for (auto shortWord : shortWords) {
                    if (isPredecessor(shortWord.first, longWord.first)) {
                        wordBySize[i][longWord.first] = wordBySize[i][longWord.first] > shortWord.second+1 ? wordBySize[i][longWord.first] : shortWord.second+1;
                        longest = longest > wordBySize[i][longWord.first] ? longest : wordBySize[i][longWord.first];
                    }
                }
            }
        }
        return longest;
    }
    bool isPredecessor(string shortWord, string longWord) {
        bool only1diff = 0;
        for (int i = 0, j = 0; i < shortWord.size();) {
            if (shortWord[i] != longWord[j]) {
                if (!only1diff) {
                    only1diff = 1;
                    ++j;
                } else {
                    return false;
                }
            } else {
                 ++i, ++j;
            }
        }
        return true;
    }
};

int main() {
    vector<string> vec{
        "a","ab","ac","bd","abc","abd","abdd"
    };
    Solution solution;
    cout << solution.longestStrChain(vec) << endl;
}