#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isSymbol (char c) {
        return c == ' ' || c =='!' || c == '?' || c == '\''
            || c == ',' || c == ';' || c == '.';
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int start = 0, end = 0, max=0;
        transform(paragraph.begin(),paragraph.end(),paragraph.begin(),::towlower);
        paragraph += " ";
        string result;
        map<string,int> word_map;;
        while (end != paragraph.size()) {
            if (isSymbol(paragraph[end]) && end > start) {
                auto str = paragraph.substr(start,end-start);
                ++word_map[str];
                if (find(banned.begin(),banned.end(),str) == banned.end() && word_map[str] > max) {
                    max = word_map[str];
                    result = str;
                }
                start = end+1;
                if (isSymbol(paragraph[start])) {
                    ++start;
                } 
            }
            ++end;
        }
        return result;
    }
};

int main() {
    string paragraph = "Bob. hIt, baLl";
    vector<string> banned{
        "bob", "hit"
    };
    Solution solution;
    cout << solution.mostCommonWord(paragraph,banned) << endl;
}