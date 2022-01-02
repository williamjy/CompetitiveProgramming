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

// dfs
class Solution {
private:
  int maximum = -1000;
public:
  int maxPathSum(TreeNode* root) {
    rec(root);
    return maximum;
  }
  int rec(TreeNode* root) {
    if (root == nullptr) return 0;
    int left = max(rec(root->left),0);
    int right = max(rec(root->right),0);
    maximum = max(maximum,left+root->val+right);
    return max(left,right)+root->val;
  }
};

int main () {
  Solution solution;
  TreeNode* root = new TreeNode(1,new TreeNode(2), new TreeNode(3));
  cout << solution.maxPathSum(root) << endl;
}