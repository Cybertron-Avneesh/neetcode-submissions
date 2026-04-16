class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto s: strs){
            ans += to_string(s.size()) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i<s.size()){
            int len = 0;
            while(i<s.size() && s[i]!='#'){
                len = len * 10 + (s[i] - '0');
                i++;
            }
            i++;
            int j = 0;
            string str = "";
            while(j<len){
                str.push_back(s[i]);
                i++;
                j++;
            }
            ans.push_back(str);
        }
        return ans;
    }
};
