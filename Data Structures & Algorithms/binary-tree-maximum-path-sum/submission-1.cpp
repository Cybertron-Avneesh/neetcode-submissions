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
    int helper(TreeNode* root, int&mx){
        if(!root) return 0;
        int leftMax = max(0, helper(root->left, mx));
        int rightMax = max(0, helper(root->right, mx));

        mx = max(mx, leftMax+rightMax + root->val);
        return max(leftMax, rightMax) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        helper(root, mx);
        return mx;
    }
};
