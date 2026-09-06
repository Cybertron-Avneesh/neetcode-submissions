class Solution {
public:
    int maxDifference(string s) {
        map<char, int> mp;
        for(auto a: s){
            mp[a]++;
        }
        vector<char> odd, even;
        for(auto [k, v]: mp){
            if(v%2==0){
                even.push_back(k);
            } else {
                odd.push_back(k);
            }
        }
        int mx = INT_MIN;
        for(int i=0; i<odd.size(); i++){
            for(int j=0;j<even.size(); j++){
                mx = max(mx, mp[odd[i]] - mp[even[j]]);
            }
        }
        return mx;
    }
};