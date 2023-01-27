#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {
private:
    map<string, function<int (int, int)>> operatorMap = {
        { "+" , [] (int a, int b) { return a + b; } },
        { "-" , [] (int a, int b) { return a - b; } },
        { "*" , [] (int a, int b) { return a * b; } },
        { "/" , [] (int a, int b) { return a / b; } }
    };
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operatorStack;
        for (auto token : tokens) {
            if (operatorMap.find(token) != operatorMap.end()) {
                int b = operatorStack.top();
                operatorStack.pop();
                int a = operatorStack.top();
                operatorStack.pop();
                operatorStack.push(operatorMap[token](a, b));
            } else {
                operatorStack.push(stoi(token));
            }
        }
        return operatorStack.top();
    }
};
