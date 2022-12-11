struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <algorithm>

using namespace std;

class Solution {
private:
    long totalSum = 0;
    long maxSumProduct = 0;
public:
    int maxProduct(TreeNode* root) {
        getTotalSum(root);
        getSubtreeSum(root);
        return (int) (maxSumProduct % 1000000007);
    }
    void getTotalSum(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        getTotalSum(root->left);
        getTotalSum(root->right);
        totalSum += root->val;
        totalSum = totalSum % 1000000007;
    }
    long getSubtreeSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        long sum = getSubtreeSum(root->left) + getSubtreeSum(root->right) + root->val;
        long otherSum = totalSum - sum;
        maxSumProduct = max(maxSumProduct, sum * otherSum);
        return sum;
    }
};