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
    int myAtoi(string s) {
        int curr = 0;
        for (;s[curr] == ' ';curr++) {
        }
        int sign = 1;
        sign = s[curr] != '-' ? 1 : -1;
        int total = 0;
        if (s[curr] == '-' || s[curr] == '+') curr++;
        for (;s[curr] <= '9' && s[curr] >= '0'; curr++) {
            int num = s[curr] - '0';
            if (total <= (0x7fffffff - num) / 10) {
                total = total * 10;
                total += num;
            } else {
                if (sign == 1) return 0x7fffffff;
                else return 0x80000000;
            }
        }
        return total * sign;
    }
};

int main() {
    string s = "2147483646";
    Solution solution;
    cout << solution.myAtoi(s) << endl;
}