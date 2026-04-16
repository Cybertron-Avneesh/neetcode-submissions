class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for(auto &s: strs){
            vector<int> arr(26, 0);
            for(auto &ch: s){
                arr[ch-'a']++;
            }
            if(mp.find(arr)!=mp.end()){
                mp[arr].push_back(s);
            } else{
                mp[arr] = {};
                mp[arr].push_back(s);
            }
        }
        vector<vector<string>> ans;
        for(auto [k, v]: mp){
            ans.push_back(v);
        }
        return ans;
    }
};
