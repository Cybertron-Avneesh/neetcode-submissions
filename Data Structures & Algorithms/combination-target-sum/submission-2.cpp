class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> &nums, int i, int target, vector<int> &curr){
        // base case
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(target<0 || i>=nums.size()){
            return;
        }
        for(int j=i; j<nums.size(); j++){
            if(target < nums[j]){
                return;
            }
            // choose only those who are below limits
            curr.push_back(nums[j]);
            helper(nums, j, target-nums[j], curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        helper(nums, 0, target, tmp);
        return ans;
    }
};
