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
  TreeNode* prev = NULL;
public:
  void flatten(TreeNode* root) {
    if (root == NULL) return;
    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left = NULL;
    prev = root;
  }
};

int main () {
}