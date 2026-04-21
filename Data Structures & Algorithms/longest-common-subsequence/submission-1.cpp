class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(s[i] == t[j]){
                    dp[i][j] = 1 + ((i==0||j==0)?0:dp[i-1][j-1]);
                } else{
                    dp[i][j] = max(((i==0)?0:dp[i-1][j]), ((j==0)?0:dp[i][j-1]));
                }
            }
        }
        return dp[n-1][m-1];
    }
};
