/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public: 
    int helper(TreeNode* root, int &mx) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int left = helper(root->left, mx);
        int right = helper(root->right, mx);
        mx = max(mx, left + right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int mx = 0;
        helper(root, mx);
        return mx;
    }
};
