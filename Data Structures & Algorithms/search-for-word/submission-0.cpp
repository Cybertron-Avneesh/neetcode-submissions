class Solution {
public:
    bool dfs(vector<vector<char>> &b, int i, int j, int k, string &word){
        if(k == word.size()) return true;
        if(i<0 || j<0 || i>=b.size() || j>=b[0].size() || b[i][j] != word[k] || b[i][j] == '#'){
            return false;
        }
        char ch = b[i][j];
        b[i][j] = '#';
        bool res = dfs(b, i+1, j, k+1, word) || 
                   dfs(b, i-1, j, k+1, word) || 
                   dfs(b, i, j+1, k+1, word) || 
                   dfs(b, i, j-1, k+1, word);
        b[i][j] = ch;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(dfs(board, i, j, 0, word)) return true;
            }
        }
        return false;
    }
};
