#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<TreeNode*> generateTrees(int n) {
    return rec(1,n);
  }

  vector<TreeNode*> rec (int start, int end) {
    if (start > end) {
      vector<TreeNode*> result;
      result.push_back(NULL);
      return result;
    }
    vector<TreeNode*> result;
    for (int i = start; i <= end; i++) {
      vector<TreeNode*> left = rec(start,i-1);
      vector<TreeNode*> right = rec(i+1,end);
      for (auto l : left) {
        for (auto r : right) {
          TreeNode* treeNode = new TreeNode(i,l,r);
          result.push_back(treeNode);
        }
      }
    }
    return result;
  }
};

int main () {
  Solution solution;
  int n = 19;
}