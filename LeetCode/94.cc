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
  vector<int> memo;
public:
  vector<int> inorderTraversal(TreeNode* root) {
    if (root == NULL) return memo;
    inorderTraversal(root->left);
    memo.push_back(root->val);
    inorderTraversal(root->right);
    return memo;
  }
};

int main () {
}