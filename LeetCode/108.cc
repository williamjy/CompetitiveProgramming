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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int half = nums.size() / 2;
        return rec(nums, 0, nums.size());
    }

    TreeNode* rec(vector<int>& nums, int start, int end) {
        if (start >= end) return NULL;
        if (start + 1 == end) return new TreeNode(nums[start]);
        int half = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[half]);
        root->left = rec(nums, start, half);
        root->right = rec(nums, half+1, end);
        return root;
    }
};