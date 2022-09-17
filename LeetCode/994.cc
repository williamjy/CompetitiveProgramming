#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void isFresh(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int,int>>& nextRotted) {
        if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && !visited[row][col]) {
            if (grid[row][col] == 1) {
                visited[row][col] = 1;
                grid[row][col] = 2;
                nextRotted.push(make_pair(row,col));
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> currRotted;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),0));
        int round = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 2) {
                    visited[row][col] = 1;
                    currRotted.push(make_pair(row,col));
                } else if (grid[row][col] == 0) {
                    visited[row][col] = 1;
                }
            }
            
        }
        while (!(round && currRotted.empty())) {
            queue<pair<int,int>> nextRotted;
            while (!currRotted.empty()) {
                auto row = currRotted.front().first;
                auto col = currRotted.front().second;
                currRotted.pop();
                isFresh(row-1,col,grid,visited,nextRotted);
                isFresh(row+1,col,grid,visited,nextRotted);
                isFresh(row,col-1,grid,visited,nextRotted);
                isFresh(row,col+1,grid,visited,nextRotted);
            }
            swap(currRotted,nextRotted);
            ++round;
        }
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    return -1;
                }
            }
            
        }
        return round-1;
    }
};