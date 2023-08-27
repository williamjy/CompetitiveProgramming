#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        const auto size = sentence.size();
        vector<int> dp; //Number of words fit if you start with kth words.
        for (int k = 0; k < size; ++k)
        {
            int currCol = 0, wordPosition = k, numOfWordsFit = 0;
            while (currCol < cols)
            {
                const auto wordLength = sentence[wordPosition].length();
                if (currCol + wordLength <= cols)
                {
                    currCol += wordLength + 1;
                    numOfWordsFit++;
                    wordPosition++;
                    if (wordPosition == size)
                    {
                        wordPosition = 0;
                    }
                }
                else if (currCol = 0)
                {
                    return 0;
                } else
                {
                    break;
                }
            }
            dp.push_back(numOfWordsFit);
        }
        int wordPosition = 0, totalWordsFit = 0;
        for (int currRow = 0; currRow < rows; ++currRow)
        {
            totalWordsFit += dp[wordPosition];
            wordPosition = totalWordsFit % size;
        }
        return totalWordsFit / size;
    }
};