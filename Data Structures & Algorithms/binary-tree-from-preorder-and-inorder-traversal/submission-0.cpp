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
    TreeNode* helper(vector<int> &preorder, vector<int> &inorder){
        if(preorder.size() == 0||inorder.size() == 0){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int inorderIdx = -1;
        for(int i=0; i<inorder.size(); i++){
            if(preorder[0] == inorder[i]){
                inorderIdx = i;
            }
        }
        // [1:mid+1] [mid+1, end]
        vector<int> leftPre(preorder.begin()+1, preorder.begin() + inorderIdx+1);
        vector<int> rightPre(preorder.begin()+inorderIdx+1, preorder.end());
        vector<int> leftIn(inorder.begin(), inorder.begin() + inorderIdx);
        vector<int> rightIn(inorder.begin()+inorderIdx+1, inorder.end());
        root->left = helper(leftPre, leftIn);
        root->right = helper(rightPre, rightIn);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder);
    }
};
