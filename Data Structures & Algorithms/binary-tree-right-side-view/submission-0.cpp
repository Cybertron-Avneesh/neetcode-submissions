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
    void dfs(TreeNode* node,int lvl, vector<int> &ans){
        if(!node) return;
        if(ans.size() == lvl){
            ans.push_back(node->val);
        } else {
            ans[lvl] = node->val;
        }
        dfs(node->left, lvl+1, ans);
        dfs(node->right, lvl+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        // use dfs and keep an array for storing last visited element for each level
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};
