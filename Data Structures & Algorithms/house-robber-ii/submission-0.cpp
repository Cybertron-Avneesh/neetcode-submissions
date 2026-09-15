class Solution {
public:
    int robHelper(vector<int> &nums, int start, int end){
        int secondLast = 0;
        int last = nums[start];
        for(int i=start+1; i<=end; i++){
            int curr = max(last, secondLast + nums[i]);
            secondLast = last;
            last = curr;
        }
        return last;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums.back();
        if(n == 2) return max(nums[0], nums[1]);
        return max(robHelper(nums, 0, n-2), robHelper(nums, 1, n-1));
    }
};
