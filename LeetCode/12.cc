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
    string intToRoman(int num) {
        map<int,string> numToRoman{
            {1, "I"},
            {5, "V"},
            {10, "X"},
            {50, "L"},
            {100, "C"},
            {500, "D"},
            {1000, "M"},
        };
        vector<int> numbers{
            1000,500,100,50,10,5,1
        };
        string result = "";
        for (int i = 0; i < numbers.size(); i++) {
            int counts = num / numbers[i];
            for (int j = 0; j < counts; j++) {
                result += numToRoman[numbers[i]];
            }
            num -= counts * numbers[i];
            if ((numbers[i] == 1000 || numbers[i] == 500) && num >= numbers[i] - 100 && num < numbers[i]) {
                result += numToRoman[100];
                result += numToRoman[numbers[i]];
                num -= (numbers[i] - 100);
            }
            if ((numbers[i] == 100 || numbers[i] == 50) && num >= numbers[i] - 10 && num < numbers[i]) {
                result += numToRoman[10];
                result += numToRoman[numbers[i]];
                num -= (numbers[i] - 10);
            }
            if ((numbers[i] == 10 || numbers[i] == 5) && num >= numbers[i] - 1 && num < numbers[i]) {
                result += numToRoman[1];
                result += numToRoman[numbers[i]];
                num -= (numbers[i] - 1);
            }
        }
        return result;
    }
};

int main () {
    int num = 2008;
    Solution solution;
    cout << solution.intToRoman(num) << endl;
}