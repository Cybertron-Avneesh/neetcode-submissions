class Solution {
public:
    int findMin(vector<int> &nums) {
        int lo=0;
        int hi = nums.size()-1;
        int minEle = INT_MAX;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            minEle = min(minEle, nums[mid]);
            if(nums[mid] <= nums[hi]){
                hi=mid-1;
            } else {
                lo = mid+1;
            }
        }
        return minEle;
    }
};
