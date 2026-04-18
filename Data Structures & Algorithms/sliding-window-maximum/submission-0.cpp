class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k-1; i++){
            pq.push({nums[i], i});
        }
        for(int i=k-1; i<nums.size(); i++){
            pq.push({nums[i], i});
            while(pq.size() && (i - k)>=(pq.top().second)){
                pq.pop();
            }
            auto top = pq.top();
            ans.push_back(top.first);
        }
        return ans;
    }
};
