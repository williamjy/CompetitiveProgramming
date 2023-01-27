#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int position = tokens.size();
        return dfs(tokens, position);
    }
    int dfs(vector<string>& tokens, int& position) {
        position--;
        if (position < 0) {
            return 1;
        }
        string token = tokens[position];
        if ((token[0] >= '0' && token[0] <= '9') || (token[0] == '-' && token.size() > 1)) {
            if (token[0] == '-') {
                return -stoi(token.substr(1, token.size() - 1));
            } else {
                return stoi(token);
            }
        }
        int first = dfs(tokens, position);
        int second = dfs(tokens, position);
        if (token[0] == '+') {
            return first + second;
        } else if (token[0] == '-') {
            return second - first;
        } else if (token[0] == '*') {
            return first * second;
        } else{
            return second / first;
        }
    }
};