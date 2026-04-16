class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> prefixProduct(n, 1);
        vector<int> suffixProduct(n, 1);
        for(int i=1; i<n; i++){
            prefixProduct[i] = prefixProduct[i-1] * nums[i-1];
        }
        for(int i=n-2; i>=0; i--){
            suffixProduct[i] = suffixProduct[i+1] * nums[i+1];
        }
        for(int i=0; i<n; i++){
            if(i==0){
                ans.push_back(suffixProduct[i]);
            } else if(i==n-1){
                ans.push_back(prefixProduct[i]);
            } else{
                ans.push_back(suffixProduct[i] * prefixProduct[i]);
            }
        }
        return ans;

    }
};
