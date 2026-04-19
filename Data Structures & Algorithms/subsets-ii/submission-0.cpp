class Solution {
public:
    void helper(vector<int> &nums, vector<int> &currSubset, int i, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(currSubset);
            return;
        }
        // pick ith 
        currSubset.push_back(nums[i]);
        helper(nums, currSubset, i+1, ans);
        currSubset.pop_back();
        
        // not pick ith -- also skip duplicates
        while(i+1<nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        helper(nums, currSubset, i+1, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> currSubset;
        vector<vector<int>> ans;
        helper(nums, currSubset, 0, ans);
        return ans;
    }
};
