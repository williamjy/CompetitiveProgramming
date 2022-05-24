#include <vector>
#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        rec(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    void rec(vector<vector<int>>& image, int sr, int sc, int parentColor, int newColor) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != parentColor) return;
        image[sr][sc] = newColor;
        rec(image, sr-1, sc, parentColor, newColor);
        rec(image, sr+1, sc, parentColor, newColor);
        rec(image, sr, sc+1, parentColor, newColor);
        rec(image, sr, sc-1, parentColor, newColor);
        return;
    }
};

int main() {
    vector<vector<int>> image{
        {0,0,0},
        {0,1,1},
    };
    Solution solution;
    image = solution.floodFill(image,1,1,1);
    for (auto i : image) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}