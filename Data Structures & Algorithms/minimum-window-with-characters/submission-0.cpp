class Solution {
public:
    string minWindow(string s, string t) {
        // approach: Sliding window
        // need to track following
        // mapt -> frequency of characters in t
        // window -> frequency of characters in s's window
        // uniqueCharsInT = mapt.size()
        // countOfCharsInTHavingMetFrequency in S
        // res = [-1, -1]
        // resultLen = INT_MAX // coz we need minimum substr
        // expand the window on r
        // add frequency of each char in window
        // update countOfCharsInTHavingMetFrequency if a characters frequency in window becomes equal to its freq in t
        // if countOfCharsInTHavingMetFrequency == uniqueCharsInT
        // we got out valid substring
        // try to shrink the substring by moving l

        if(t.size() == 0) return "";
        unordered_map<char, int> mapt;
        unordered_map<char, int> window;

        for(auto a: t){
            mapt[a]++;
        }
        int uniqueCount = mapt.size();
        int metCount = 0;
        int resLen = INT_MAX;
        vector<int> resIdx = {-1, -1};

        int l = 0;
        for(int r=0; r<s.size(); r++){
            window[s[r]]++;
            if(mapt.count(s[r]) && window[s[r]] == mapt[s[r]]){
                metCount++;
            }
            while(metCount == uniqueCount){
                if((r-l+1) < resLen){
                    resLen = min(resLen, (r-l+1));
                    resIdx = {l, r};
                }
                // shrink the window
                window[s[l]]--;
                if(mapt.count(s[l]) && window[s[l]] < mapt[s[l]]){
                    metCount--;
                }
                l++;
            }
        }
        if(resLen == INT_MAX) return "";
        return s.substr(resIdx[0], resIdx[1] - resIdx[0]+1);
    }
};
