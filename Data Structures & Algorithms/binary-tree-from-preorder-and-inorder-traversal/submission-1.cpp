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
    int preIdx = 0;
    int inIdx = 0;
    TreeNode* f(int limit, vector<int>& preorder, vector<int>& inorder){
        if(preIdx>=preorder.size()){
            return nullptr;
        }
        if(limit == inorder[inIdx]){
            inIdx++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preIdx]);
        preIdx++;
        root->left = f(root->val, preorder, inorder);
        root->right = f(limit, preorder, inorder); // limit here will remain as it needs to build more
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return f(INT_MIN, preorder, inorder);
    }
};
