#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <unordered_set>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string from, string to, vector<string>& wordList) {
        vector<vector<string>> results;
        unordered_set<string> lexicon;
        for (auto w : wordList) {
            lexicon.insert(w);
        }
        if (lexicon.find(to) == lexicon.end()) {
            return results;
        }
		bool isDirectionForward = true, isFound = false;
		map<string, vector<string>> childWords;
		unordered_set<string> remainLexicon = lexicon;
		unordered_set<string> heads{from}, tails{to};
		remainLexicon.erase(from);
		remainLexicon.erase(to);
		while (!heads.empty() && !tails.empty()) {
			if (heads.size() > tails.size()) {
				swap(heads, tails);
				isDirectionForward = !isDirectionForward;
			}
			unordered_set<string> nextWords;
			for (auto word : heads) {
				for (unsigned long position = 0; position < word.size(); position++) {
					for (char letter = 'a'; letter <= 'z'; letter++) {
						if (word[position] == letter) {
							continue;
						}
						auto nextWord = word;
						nextWord[position] = letter;
						if (tails.find(nextWord) != tails.end()) {
							isFound = true;
							if (isDirectionForward) {
								childWords[word].push_back(nextWord);
							} else {
								childWords[nextWord].push_back(word);
							}
						} else if (!isFound && remainLexicon.find(nextWord) != remainLexicon.end()) {
							nextWords.insert(nextWord);
							if (isDirectionForward) {
								childWords[word].push_back(nextWord);
							} else {
								childWords[nextWord].push_back(word);
							}
						}
					}
				}
			}
			if (isFound) {
				break;
			}
			for (auto nextWord : nextWords) {
				remainLexicon.erase(nextWord);
			}
			heads = nextWords;
		}
		vector<string> path{from};
		findPath(from, to, childWords, path, results);
		return results;
	}

	void findPath (string const& from, string const& to, map<string, vector<string>>& childWords, vector<string> &path, vector<vector<string>> &results) {
		if (from == to) {
			results.push_back(path);
		}
		for (auto nextWord : childWords[from]) {
			path.push_back(nextWord);
			findPath(nextWord, to, childWords, path, results);
			path.pop_back();
		}
	}
};

int main() {
    Solution solution;
    string from = "hit";
    string to = "cog";
    
    vector<string> wordList{
        "hot","dot","dog","lot","log","cog", "hiz"
    };
    auto results = solution.findLadders(from, to, wordList);
    for (auto v : results) {
        for (auto w : v) {
            cout << w << " ";
        }
        cout << endl;
    }
}