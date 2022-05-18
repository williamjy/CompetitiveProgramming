#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int prev = 0;
        int curr = 0;
        int num = 0;
        vector<int> numbers{
            1000,500,100,50,10,5,1
        };
        vector<string> romans{
            "M","D","C","L","X","V","I"
        };
        map<char,int> romanToNum{
            {'M',1000},
            {'D',500},
            {'C',100},
            {'L',50},
            {'X',10},
            {'V',5},
            {'I',1},
        };
        while (curr < s.size()-1) {
            prev = curr;
            curr++;
            if (romanToNum[s[prev]] < romanToNum[s[curr]]) {
                num -= romanToNum[s[prev]];
            } else {
                num += romanToNum[s[prev]];
            }
        }
        num += romanToNum[s[curr]];
        return num;
    } 
};

int main () {
    string s = "MCMXCIV";
    Solution solution;
    cout << solution.romanToInt(s) << endl;
}