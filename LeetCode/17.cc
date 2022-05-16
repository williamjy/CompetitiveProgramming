#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
private:
    string tmp;
    vector<string> results{};
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return results;
        rec(digits,0);
        return results;
    }
    void rec(string digits, int position) {
        static map<char,vector<char>> digitsMap {
            {'2',vector<char> {'a','b','c'}},
            {'3',vector<char> {'d','e','f'}},
            {'4',vector<char> {'g','h','i'}},
            {'5',vector<char> {'j','k','l'}},
            {'6',vector<char> {'m','n','o'}},
            {'7',vector<char> {'p','q','r','s'}},
            {'8',vector<char> {'t','u','v'}},
            {'9',vector<char> {'w','x','y','z'}},            
        }; 
        if (position == digits.size()) {
            results.push_back(tmp);
            return;
        }
        for (auto curr : digitsMap[digits[position]]) {
            tmp += curr;
            rec(digits,position+1);
            tmp.pop_back();
        }
    }
};

int main () {
    Solution solution;
    string digits = "35";
    auto answer = solution.letterCombinations(digits);
    for (auto i : answer) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}