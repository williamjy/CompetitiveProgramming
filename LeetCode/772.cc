#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        s += "+0";
        int result = 0;
        bool bIsPlusResult = true;
        bool bIsPrevCharDigit = false;
        queue<char> operatorStack;
        queue<int> numStack;
        for (auto i = 0; i < s.size(); i++) {
            if (s[i] == '+' || s[i] == '-') {
                int currResult = numStack.front();
                numStack.pop();
                while (!operatorStack.empty()) {
                    char currOperator = operatorStack.front();
                    operatorStack.pop();
                    int currNum = numStack.front();
                    numStack.pop();
                    if (currOperator == '*') {
                        currResult *= currNum;
                    } else if (currOperator == '/') {
                        currResult /= currNum;
                    }
                }
                if (bIsPlusResult) {
                    result += currResult;
                } else {
                    result -= currResult;
                }
                bIsPrevCharDigit = false;
                bIsPlusResult = s[i] == '+' ? 1 : 0;
            } else if (s[i] == '*' || s[i] == '/') {
                bIsPrevCharDigit = false;
                operatorStack.push(s[i]);
            } else if (s[i] == '(') {
                int start = i + 1;
                int parenthesisLoop = 1;
                while (parenthesisLoop != 0) {
                   i++;
                   if (s[i] == '(') {
                        parenthesisLoop++;
                   } else if (s[i] == ')') {
                        parenthesisLoop--;
                   }
                }
                int number = calculate(s.substr(start, i - start));
                numStack.push(number);
                bIsPrevCharDigit = false;
            } else {
                int digit = s[i] - '0';
                if (bIsPrevCharDigit) {
                    numStack.back() *= 10;
                    numStack.back() += digit;
                } else {
                    numStack.push(digit);
                }
                bIsPrevCharDigit = true;
            }
        }
        return result;
    }
};