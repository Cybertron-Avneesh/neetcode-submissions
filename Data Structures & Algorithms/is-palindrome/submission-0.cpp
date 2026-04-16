class Solution {
public:
    bool isPalindrome(string s) {
        string n = "";
        for(auto ch: s){
            if(ch >= 'A' && ch<='Z'){
                // to lower case
                ch = ch + ('a' - 'A');
            } else if((ch>='a' && ch<='z') || (ch >= '0' && ch <= '9')){
                ch = ch;
            } else {
                continue;
            }   
            n.push_back(ch);
        }
        int i=0;
        int j=n.size()-1;
        while(i<=j){
            if(n[i] != n[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
