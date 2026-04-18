class Solution {
public:
    int characterReplacement(string s, int k) {
        // Approach: Sliding window with hashmap
        // take l=0 and maxFrequency = 0 
        // define result = 0
        // start expanding the window by iterating over the string (r)
        // consider that if s[r] is the character that i want to keep 
        // this implies, rest of the characters must change
        // hence maxFrequency = max(max, count[s[r]])
        // maxFrequency is going to increase monotonically, it is the historical upper bound
        // we are reducing cost of recomputing maxFrequency each time we update the hash map
        // since maxFrequency gave us a probably answer, 
        // if it increases that means it can give a next probably answer
        int l = 0;
        int maxFreq = 0;
        unordered_map<char, int> mp;
        int ans = 0;
        for(int r=0; r<s.size(); r++){
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            while(((r-l+1) - maxFreq) > k){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
