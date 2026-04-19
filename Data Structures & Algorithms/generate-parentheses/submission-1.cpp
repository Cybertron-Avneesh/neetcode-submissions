class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0] = {""};
        // ( left ) right -> left and right are already a valid parantheses
        // left len(open brackets only) =  i
        // right's len = n-i-1
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                vector<string> left = dp[j];
                vector<string> right = dp[i-j-1];
                for(auto a: left){
                    for(auto b: right){
                        string newStr = "(" + a + ")" + b;
                        dp[i].push_back(newStr);
                    }
                }
            }
        }
        return dp[n];
    }
};
