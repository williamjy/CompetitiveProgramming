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

// [2,1,4,null,null,3]
// []
// [0]

class Solution {
private:
  TreeNode* prev;
public:
  void flatten(TreeNode* root) {
    if (root == NULL) return;
    prev = root;
    flatten(root->left);
    TreeNode* left = prev;
    flatten(root->right);
    TreeNode* right = prev;
    left->right = root->right;
    if (root->left != NULL) {
      root->right = root->left;
      root->left = NULL;
   }
    return;
  }
};

int main () {
}