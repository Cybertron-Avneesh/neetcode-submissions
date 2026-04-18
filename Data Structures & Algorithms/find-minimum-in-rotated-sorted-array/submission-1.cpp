class Solution {
public:
    int findMin(vector<int> &nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        int ans = INT_MAX;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            // if left part is sorted, lo might be a potential answer
            if(nums[lo] <= nums[mid]){ // use = for single element array
                ans = min(ans, nums[lo]);
                lo = mid+1;
            } else {
                // right part is sorted, first element of right part would be the potential answer
                ans = min(ans, nums[mid]);
                hi = mid-1;
            }
        }
        return ans;
    }
};
