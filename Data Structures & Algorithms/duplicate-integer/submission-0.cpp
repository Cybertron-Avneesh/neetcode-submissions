class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto a: nums){
            if(mp.find(a) != mp.end()) return true;
            mp[a] = 1;
        }
        return false;
    }
};