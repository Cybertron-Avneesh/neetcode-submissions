class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);
        for(int i=0; i<s1.size(); i++){
            mp1[s1[i] - 'a']++;
            mp2[s2[i] - 'a']++;
        }
        int i = s1.size()-1;
        while(i<s2.size()){
            bool diff = false;
            for(int j=0; j<26; j++){
                if(mp1[j] != mp2[j]){
                    diff = true;
                    break;
                }
            }
            if(!diff) return true;
            i++;
            if(i<s2.size()){
                mp2[s2[i-s1.size()] - 'a']--;
                mp2[s2[i] - 'a']++;
            }
        }
        return false;
    }
};
