class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // approach: Sliding window
        // keep a set of characters and two pointers l and r
        // expand r, whenever a characters appears at r which is already in char set
        // move l till char at s[r] is removed from set
        // Approach: Sliding Window + HashMap
        // keep a hashmap for storing last position of the char
        // keep a l index to store the staring point
        // if a character aleady exists in the map, update the l = mp[s[r]] + 1
        // update mp[s[r]] = r
        // keep track of max length

        int l = 0;
        int maxLen = 0;
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                // already exists
                l = max(mp[s[i]] + 1, l);
                mp[s[i]] = i;
                maxLen = max(maxLen, i - l + 1);
            } else {
                // new char
                mp[s[i]] = i;
                maxLen = max(maxLen, i - l + 1);
            }
        }
        return maxLen;
    }
};
