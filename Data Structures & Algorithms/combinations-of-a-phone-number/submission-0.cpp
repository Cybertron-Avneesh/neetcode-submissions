class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans= {""};
        for(char d: digits){
            vector<string> tmp;
            for(string &currStr: ans){
                for(char ch: mp[d-'0']){
                    tmp.push_back(currStr+ch);
                }
            }
            ans = tmp;
        }
        return ans;
    }
};
