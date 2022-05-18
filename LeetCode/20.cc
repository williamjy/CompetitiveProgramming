#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() & 1) return 0;
        map<char,char> leftToRight{
            {'(',')'},
            {'{','}'},
            {'[',']'},
        };
        vector<char> stack;
        for (auto left : s) {
            if (left == '(' || left == '{' || left == '[') {
                stack.push_back(leftToRight[left]);
            } else if (stack.empty()) {
                return 0;
            } else {
                char right = stack.back();
                stack.pop_back();
                if (left != right) return 0;
            }
        }
        return stack.empty();
    }
};

int main() {
    string s = "((";
    Solution solution;
    cout << solution.isValid(s) << endl;
}