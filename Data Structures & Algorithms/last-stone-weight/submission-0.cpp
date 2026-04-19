class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0; i<stones.size(); i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int top = pq.top(); pq.pop();
            int top2 = pq.top(); pq.pop();
            if(top == top2){
                continue;
            } else {
                pq.push(abs(top - top2));
            }
        }
        return pq.size()==0?0:pq.top();
    }
};
