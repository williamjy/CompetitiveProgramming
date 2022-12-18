#include <vector>
#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> results;
        int currentPosition = 0;
        while (currentPosition < words.size()) {
            vector<string> wordsToBeInserted;
            wordsToBeInserted.push_back(words[currentPosition]);
            int rowSize = words[currentPosition].size();
            while (currentPosition + wordsToBeInserted.size() < words.size()) {
                if (rowSize + words[currentPosition + wordsToBeInserted.size()].size() + 1 <= maxWidth) {
                    rowSize += (words[currentPosition + wordsToBeInserted.size()].size() + 1);
                    wordsToBeInserted.push_back(words[currentPosition + wordsToBeInserted.size()]);
                } else {
                    break;
                }
            }
            int totelExtraSpaces = maxWidth - rowSize;
            assert(wordsToBeInserted.size() > 0);
            string row = wordsToBeInserted[0];
            if (wordsToBeInserted.size() == 1 || currentPosition + wordsToBeInserted.size() == words.size()) {
                // Last row
                for (int i = 1; i < wordsToBeInserted.size(); i++) {
                    row += " ";
                    row += wordsToBeInserted[i];
                }
                row.insert(row.size(), maxWidth-row.size(),' ');
            } else {
                int extraSpacesBetweenTwoWords = totelExtraSpaces / (wordsToBeInserted.size() - 1);
                int extraSpacesLeft = totelExtraSpaces % (wordsToBeInserted.size() - 1);
                for (int i = 1; i < wordsToBeInserted.size(); i++) {
                    row += " ";
                    row.insert(row.size(), extraSpacesBetweenTwoWords,' ');
                    if (extraSpacesLeft > 0) {
                        row += " ";
                        extraSpacesLeft--;
                    }
                    row += wordsToBeInserted[i];
                }
            }
            currentPosition += (int) wordsToBeInserted.size();
            results.push_back(row);
        }
        return results;
    }
};

int main() {
    Solution solution;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    auto results = solution.fullJustify(words, maxWidth);
    for (auto w : results) {
        cout << w << endl;
    }
}

