#include <vector>
#include <iostream>
#include <math.h>
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
private:
  vector<vector<int>> answers;
  vector<int> stack;
public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    rec(root,targetSum);
    return answers;
  }
  void rec(TreeNode* root, int targetSum) {
    if (root == NULL) return;
    if (root->val == targetSum && root->left == NULL && root->right == NULL) {
      stack.push_back(root->val);
      answers.push_back(stack);
      stack.pop_back();
      return;
    }
    stack.push_back(root->val);
    rec(root->left,targetSum-root->val);
    rec(root->right,targetSum-root->val);
    stack.pop_back();
    return;
  }
};

int main () {
}