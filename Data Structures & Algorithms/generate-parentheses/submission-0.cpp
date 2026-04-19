class Solution {
public:
    void backtrack(int &open, int &close, int &n, vector<string> &ans, string &curr){
        if(open == close && open == n){
            ans.push_back(curr);
            return;
        }

        if(open<n){
            curr.push_back('(');
            open++;
            backtrack(open, close, n, ans, curr);
            open--;
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            close++;
            backtrack(open, close, n, ans, curr);
            close--;
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        vector<string> ans;
        int open = 0;
        int close = 0;
        backtrack(open, close, n, ans, curr);
        return ans;
    }
};
