#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        long prev_two_ = 6, prev_three_ = 6, current_two_ = 0, current_three_ = 0;
        while (--n) {
            current_two_ = prev_two_ * 3 + prev_three_ * 2;
            current_three_ = prev_two_ * 2 + prev_three_ * 2;
            prev_two_ =  current_two_ % 1000000007;
            prev_three_ =  current_three_ % 1000000007;
        }
        return (int) (prev_two_ + prev_three_) % 1000000007;
    }
};