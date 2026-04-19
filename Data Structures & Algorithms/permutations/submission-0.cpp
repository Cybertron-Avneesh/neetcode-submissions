class Solution {
public:
    void backtrack(vector<int> &nums, vector<int> &currPerm, vector<bool> &picked, vector<vector<int>> &ans){
        if(nums.size() == currPerm.size()){
            ans.push_back(currPerm);
            return;
        }
        // try to pick unpicked numbers by iterating over the list
        for(int i=0; i<nums.size(); i++){
            if(picked[i] == false){
                currPerm.push_back(nums[i]);
                picked[i] = true;
                backtrack(nums, currPerm, picked, ans);
                picked[i] = false;
                currPerm.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> picked(n, false);
        vector<vector<int>> ans;
        vector<int> currPerm;
        backtrack(nums, currPerm, picked, ans);
        return ans;
    }
};
