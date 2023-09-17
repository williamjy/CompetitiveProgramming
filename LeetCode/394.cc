#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> numberStack;
        stack<string> stringStack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                int number = 0;
                while (s[i] >= '0' && s[i] <= '9') {
                    number = number * 10 + s[i] - '0';
                    ++i;
                }
                --i;
                numberStack.push(number);
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                if (stringStack.empty() || stringStack.top() == "[") {
                    stringStack.push(string(1, s[i]));
                } else {
                    stringStack.top() += string(1, s[i]);
                }
            } else if (s[i] == '[') {
                stringStack.push("[");
            } else if (s[i] == ']') {
                string curr = "";
                while (!stringStack.empty() && stringStack.top() != "[") {
                    curr += stringStack.top();
                    stringStack.pop();
                }
                stringStack.pop();
                int times = 1;
                if (!numberStack.empty()) {
                    times = numberStack.top();
                    numberStack.pop();
                }
                string stringToPush = "";
                while (times--) {
                    stringToPush += curr;
                }
                if (stringStack.empty() || stringStack.top() == "[") {
                    stringStack.push(stringToPush);
                } else {
                    stringStack.top() += stringToPush;
                }
            }
        }
        return stringStack.top();
    }
};