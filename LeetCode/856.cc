#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> numStack;
        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                numStack.push(-1);
            } else {
                int score = 0;
                while (!numStack.empty() && numStack.top() != -1) {
                    auto currScore = numStack.top();
                    numStack.pop();
                    score += currScore;
                }
                numStack.pop();
                if (score == 0) {
                    numStack.push(1);
                } else {
                    numStack.push(score * 2);
                }
            }
        }
        int totalScore = 0;
        while (!numStack.empty()) {
            auto currScore = numStack.top();
            numStack.pop();
            totalScore += currScore;
        }
        return totalScore;
    }
};