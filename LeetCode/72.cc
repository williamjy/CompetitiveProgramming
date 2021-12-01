#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    int prev = 0;
    int tmp = 0;
    vector<int> memo(m+1,0);
    for (int i = 0; i <=m; i++) {
      memo[i] = i;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        tmp = memo[j];
        if (j == 0) memo[j] = i;
        else if (word1[i-1] == word2[j-1]) memo[j] = prev;
        else memo[j] = memo[j-1] < memo[j] ? (prev < memo[j-1] ? prev+1 : memo[j-1]+1) : (prev < memo[j] ? prev+1 : memo[j]+1);
        prev = tmp;
      }
    }
    return memo[m];
  }
};

int main () {
  Solution solution;
  string word1 = "horse";
  string word2 = "ros";
  cout << solution.minDistance(word1,word2) << endl;
}