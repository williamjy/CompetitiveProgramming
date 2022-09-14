#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct letter_cmp {
        bool operator() (const string& left, const string& right) {
            auto position1 = left.find(" ");
            auto position2 = right.find(" ");
            if (left.substr(position1+1,left.size()) == right.substr(position2+1,right.size())) {
                return left.substr(0,position1) <= right.substr(0,position2);
            } else {
                return left.substr(position1+1,left.size()) <= right.substr(position2+1,right.size());
            }
            return false;
        }
    };

    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letter_log;
        vector<string> digit_log;
        for (auto log : logs) {
            auto position = log.find(" ");
            if (log[position+1] >= '0' && log[position+1] <= '9') {
                digit_log.push_back(log);
            } else {
                letter_log.push_back(log);
            }
        }
        sort(letter_log.begin(),letter_log.end(),letter_cmp());
        letter_log.insert(letter_log.end(),digit_log.begin(),digit_log.end());
        return letter_log;
    }
};

int main () {
  Solution solution;
  vector<string> logs{
    "dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero",
  };
  auto results = solution.reorderLogFiles(logs);
  for (auto i : results) {
    cout << i << endl;
  }
}