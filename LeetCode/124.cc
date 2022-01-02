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
    int left = rec(root->left);
    left = left > 0 ? left : 0;
    int right = rec(root->right);
    right = right > 0 ? right : 0;
    maximum = maximum > left+root->val+right ? maximum : left+root->val+right;
    return left > right ? left + root->val : right + root->val;
  }
};

int main () {
  Solution solution;
  TreeNode* root = new TreeNode(1,new TreeNode(2), new TreeNode(3));
  cout << solution.maxPathSum(root) << endl;
}