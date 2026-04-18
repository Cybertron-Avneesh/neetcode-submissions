class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stk.push(s[i]);
            } else{
                if(stk.size() == 0) return false;
                if(stk.size()){
                    char top = stk.top();
                    if(top == '(' && s[i] == ')' || 
                       top == '[' && s[i] == ']' || 
                       top == '{' && s[i] == '}'){
                        stk.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        return stk.size()==0;
    }
};
