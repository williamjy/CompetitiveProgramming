#include <vector>
#include <iostream>

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

    vector<int> tmp;

public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> results;
        while (root != nullptr && root->val != -101) {
            dfs(root);
            results.push_back(tmp);
            tmp.clear();
        }
        return results;
    }
    void dfs (TreeNode* root) {
        if ((root->left == nullptr || root->left->val == -101) && (root->right == nullptr || root->right->val == -101)) {
            tmp.push_back(root->val);
            root->val = -101;
            return;
        }
        if (root->left != nullptr && root->left->val != -101) {
            dfs(root->left);
        }
        if (root->right != nullptr && root->right->val != -101) {
            dfs(root->right);
        }
        return;
    }
};

int main() {
    TreeNode a(3);
    TreeNode b(4);
    TreeNode c(5);
    TreeNode d(2, &a, &b);
    TreeNode root(1, &d, &c);
    Solution solutinon;
    auto results = solutinon.findLeaves(&root);
    for (auto result : results) {
        for (auto i : result) {
            cout << i << " ";
        }
        cout << endl;
    }
}