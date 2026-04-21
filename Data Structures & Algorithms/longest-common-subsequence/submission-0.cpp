class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int j, string &s, string &t){
        // base case: out of bound
        if(i<0 || j<0) return 0;
        // main case
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = 1 + f(i-1, j-1, s, t);
        }
        return dp[i][j] = max(f(i-1, j, s,t), f(i, j-1, s, t));
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size());
        for(int i=0; i<text1.size(); i++){
            dp[i].resize(text2.size(), -1);
        }
        return f(text1.size()-1, text2.size()-1, text1, text2);
    }
};
