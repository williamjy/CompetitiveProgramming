#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preRoot = 0;
        return rec(preorder, inorder, preRoot, 0, inorder.size());
    }
    TreeNode* rec(vector<int>& preorder, vector<int>& inorder, int &preRoot, int inBegin, int inEnd) {
        if (inBegin >= inEnd) return NULL;
        int i;
        for (i = 0; i < inEnd; i++) {
            if (inorder[i] == preorder[preRoot]) {
                break;
            }
        }
        TreeNode *root = new TreeNode(preorder[preRoot]);
        preRoot++;
        root->left = rec(preorder, inorder, preRoot, inBegin, i);
        root->right = rec(preorder, inorder, preRoot, i+1, inEnd);
        return root;
    }
};