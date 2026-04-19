/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* root, unordered_map<Node*, Node*> &mp){
        if(!root) return nullptr;
        if(mp.find(root) != mp.end()){
            return mp[root];
        }
        Node* copy = new Node(root->val);
        mp[root] = copy;
        for(auto nei: root->neighbors){
            copy->neighbors.push_back(dfs(nei, mp));
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        dfs(node, mp);
        return mp[node];
    }
};
