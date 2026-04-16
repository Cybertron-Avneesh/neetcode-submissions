class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> arr;
        for(auto [k, v]: mp){
            arr.push_back({v, k});
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for(int i=arr.size()-1; i>=0; i--){
            ans.push_back(arr[i][1]);
            k--;
            if(k<=0){
                break;
            }
        }
        return ans;
    }
};
