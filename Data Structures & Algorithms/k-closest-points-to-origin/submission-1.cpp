class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> pq;
        for(int i=0; i<points.size(); i++){
            auto point = points[i];
            double dis = sqrt(point[0] * point[0] + point[1] * point[1]);
            pq.push({dis, i});
            while(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(pq.size()){
            auto top = pq.top();
            pq.pop();
            ans.push_back(points[top.second]);
        }
        return ans;
    }
};
