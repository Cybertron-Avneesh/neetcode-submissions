class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> stk;
        vector<int> ans;
        for(int i=temp.size()-1; i>=0; i--){
            while(stk.size() && temp[stk.top()] <= temp[i]){
                stk.pop();
            }

            if(stk.size() == 0){
                ans.push_back(0);
                stk.push(i);
            } else {
                ans.push_back(stk.top() - i);
                stk.push(i);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
