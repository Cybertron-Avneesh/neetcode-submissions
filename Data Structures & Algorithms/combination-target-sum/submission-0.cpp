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
        // not choose
        helper(nums, i+1, target, curr);
        // choose
        curr.push_back(nums[i]);
        helper(nums, i, target - nums[i], curr);
        curr.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> tmp;
        helper(nums, 0, target, tmp);
        return ans;
    }
};
