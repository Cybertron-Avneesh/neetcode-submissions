class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 1st approach: 3 nested loops
        // 2nd approach: fix i, interate over j(=i+1 to n) 
        // and use hashmap to find existence of 3rd number
        // 3rd approach: 
        // - sort array, 
        // - fix i, l=i+1, r = n-1, move two pointers towards each other
        // - SKIP duplicates during iterations.
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int l = i+1;
            int r = n-1;
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && nums[l+1] == nums[l]){
                        l++;
                    }
                    while(l<r && nums[r-1] == nums[r]){
                        r--;
                    }
                    l++;
                    r--;
                } else if(sum < 0){
                    l++;
                } else {
                    r--;
                }
            }
        }
        return ans;
    }
};