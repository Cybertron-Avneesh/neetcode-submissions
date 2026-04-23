class Solution {
public:
    int f(int idx, vector<int> &coins, int amt, vector<vector<int>> &dp){
        // base: out of bound case
        if(idx<0){
            if(amt == 0){
                return 0;
            } else {
                return 1e6;
            }
        }
        if(amt == 0){
            return 0;
        }
        if(dp[idx][amt] != 1e6){
            return dp[idx][amt];
        }
        // main
        int minWay = 1e6;
        if(coins[idx]<=amt){
            minWay = min(minWay, 1+f(idx, coins, amt-coins[idx], dp));
        }
        minWay = min(minWay, f(idx-1, coins, amt, dp));
        return dp[idx][amt] = minWay;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1));
        for(int i=0;i<coins.size(); i++){
            for(int j=0; j<=amount; j++){
                dp[i][j] = 1e6;
            }
        }
        int ans = f(coins.size()-1, coins, amount, dp);
        if(ans == 1e6){
            return -1;
        }
        return ans;
    }
};
