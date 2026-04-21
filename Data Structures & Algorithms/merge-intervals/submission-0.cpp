class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i=0; i<intervals.size(); i++){
            if(i==0){
                ans.push_back(intervals[i]);
            } else{
                vector<int> top = ans.back();
                if(top[1] >= intervals[i][0]){
                    top[1] = max(top[1], intervals[i][1]);
                    ans.pop_back();
                    ans.push_back(top);
                } else {
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
};
