class Solution {
public:
    int timeTaken(int k, vector<int> &piles){
        int h = 0;
        for(int i=0; i<piles.size(); i++){
            h += piles[i] / k + ((piles[i]%k)>0?1:0);
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int tt = timeTaken(mid, piles);
            if(tt<=h){
                ans = min(ans, mid);
                hi = mid-1;
            } else{
                lo = mid+1;
            }
        }
        return ans;
    }
};
