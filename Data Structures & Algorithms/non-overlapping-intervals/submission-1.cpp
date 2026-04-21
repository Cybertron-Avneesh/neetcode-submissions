class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> curr = {INT_MIN, INT_MIN};
        int rem = 0;
        for(int i=0; i<intervals.size(); i++){
            if(curr[1] <= intervals[i][0]){
                // no overlap
                curr = intervals[i];
            } else {
                // overlap
                curr[1] = min(curr[1], intervals[i][1]);
                rem++;
            }
        }
        return rem;
    }
};
