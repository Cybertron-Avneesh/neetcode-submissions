class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l=0;
        int r=0;
        int maxLen = 0;
        while(r<s.size()){
            if(mp.find(s[r]) != mp.end()){
                l = max(l, mp[s[r]]+1);
                mp[s[r]] = r;
            } else {
                mp[s[r]] = r;
            }
            int len = r-l+1;
            maxLen = max(len, maxLen);
            r++;
        }
        return maxLen;
    }
};
