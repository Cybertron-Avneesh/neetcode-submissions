class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leftMin = INT_MAX;
        int maxAns = 0;
        for(int i=0; i<prices.size(); i++){
            leftMin = min(leftMin, prices[i]);
            maxAns = max(maxAns, prices[i] - leftMin);
        }
        return maxAns;
    }
};
