class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid] == target){
                return mid;
            }
            //either left is sorted and target exists there
            if(nums[lo] <= nums[mid]){
                if(nums[lo] <=target && target <= nums[mid]){
                    hi = mid-1;
                } else {
                    lo = mid+1;
                }
            } else {
                // right is sorted
                if(nums[mid] <=target && target <= nums[hi]){
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            }
        }
        return -1;
    }
};
