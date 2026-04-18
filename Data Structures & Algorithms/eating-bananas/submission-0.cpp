class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            int timeTakenToEat = 0;
            for(int p: piles){
                timeTakenToEat += (p / mid) + (p%mid?1:0); 
            }
            if(timeTakenToEat <= h){
                ans = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return ans;
    }
};
