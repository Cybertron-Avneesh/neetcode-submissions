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

class Codec {
public:
    void dfs(TreeNode* root, vector<string> &ans){
        if(root==nullptr){
            ans.push_back("N");
            return;
        }
        ans.push_back(to_string(root->val));
        dfs(root->left, ans);
        dfs(root->right, ans);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> ser;
        dfs(root, ser);
        string ans = "";
        for(auto a: ser){
            ans+=a;
            ans.push_back(',');
        }
        ans.pop_back();
        return ans;
    }

    vector<string> split(string &data){
        stringstream stream(data);
        string token;
        vector<string> tokens;
        while(getline(stream, token, ',')){
            tokens.push_back(token);
        }
        return tokens;
    }

    TreeNode* dfsDes(vector<string> &tokens, int &idx){
        if(tokens[idx] == "N"){
            idx++;
            return nullptr;
        }
        int num = stoi(tokens[idx]);
        TreeNode* root = new TreeNode(num);
        idx++;
        root->left = dfsDes(tokens, idx);
        root->right = dfsDes(tokens, idx);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens = split(data);
        int i=0;
        TreeNode*root = dfsDes(tokens, i);
        return root;
    }
};
