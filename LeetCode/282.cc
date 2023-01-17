#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    string m_operand = "";
    vector<string> m_results;

public:
    vector<string> addOperators(string num, int target) {
        m_operand += num[0];
        dfs(1, num, target, num[0] - '0', num[0] - '0');
        return m_results;
    }
    void dfs(int start, string num, int target, int lastProduct, int lastNumber) {
        if (start == num.size()) {
            if (lastProduct == target) {
                m_results.push_back(m_operand);
            }
            return;
        }
        int digit = num[start] - '0';
        auto tmp = m_operand;
        // *
        m_operand += "*";
        m_operand += num[start];
        if (digit == 0 || (INT_MIN / digit < lastProduct && INT_MAX / digit > lastProduct)) {
            dfs(start + 1, num, target, lastProduct * digit, digit);
        }
        m_operand = tmp;
        // -
        m_operand += "-";
        m_operand += num[start];
        if ((lastProduct >= 0 && INT_MIN+lastProduct <= target) || (lastProduct <= 0 && INT_MAX+lastProduct >= target)) {
            dfs(start + 1, num, target - lastProduct, -digit, digit);
        }
        m_operand = tmp;
        // +
        m_operand += "+";
        m_operand += num[start];
        if ((lastProduct >= 0 && INT_MIN+lastProduct <= target) || (lastProduct <= 0 && INT_MAX+lastProduct >= target)) {
            dfs(start + 1, num, target - lastProduct, digit, digit);
        }
        m_operand = tmp;
        // no operator
        if (lastNumber != 0 && lastProduct >= 0 && lastNumber <= (INT_MAX - digit) / 10 && INT_MAX / (lastNumber * 10 + digit) >= (lastProduct / lastNumber)) {
            int newProduct = lastProduct / lastNumber * (lastNumber * 10 + digit);
            m_operand += num[start];
            dfs(start + 1, num, target, newProduct, lastNumber*10+digit);
            m_operand = tmp;
        } else if (lastNumber != 0 && lastProduct < 0 && lastNumber <= (INT_MAX - digit) / 10 && INT_MIN / (lastNumber * 10 - digit) <= (lastProduct / lastNumber)) {
            int newProduct = lastProduct / lastNumber * (lastNumber * 10 + digit);
            m_operand += num[start];
            dfs(start + 1, num, target, newProduct, lastNumber*10+digit);
            m_operand = tmp;
        }
    }
};