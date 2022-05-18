#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int record[k+1][2];
        for (int j = 0; j <= k; j++) {
            record[j][0] = -1000;
            record[j][1] = 0;
        }
        for (auto price : prices) {
            for (int j = k; j > 0; j--) {
                record[j][1] = record[j][1] > record[j][0] + price ? record[j][1] : record[j][0] + price;
                record[j][0] = record[j][0] > record[j-1][1] - price ? record[j][0] : record[j-1][1] - price;
            }
        }
        return record[k][1];
    }
};