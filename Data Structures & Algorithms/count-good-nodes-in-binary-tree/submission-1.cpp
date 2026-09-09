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
    void dfs(TreeNode* root, int mx, int &ans){
        if(root == nullptr) return;
        if(root->val >= mx){
            ans++;
        }
        dfs(root->left, max(mx, root->val), ans);
        dfs(root->right, max(mx, root->val), ans);
    }
    int goodNodes(TreeNode* root) { 
        int ans = 0;
        dfs(root, INT_MIN, ans);
        return ans;
    }
};
