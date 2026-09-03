class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int,int>> h(26, pair<int,int>(0,INT_MAX));
        int idx = INT_MAX;
        for(int i=0; i<s.size(); i++){
            h[s[i]-'a'].first++;
            h[s[i]-'a'].second = min(h[s[i]-'a'].second, i);
        }
        for(int i=0; i<26; i++){
            if(h[i].first == 1){
                idx = min(h[i].second, idx);
            }
        }
        return idx == INT_MAX?-1:idx;
    }
};