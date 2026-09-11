class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if((left.size() + right.size())%2==0){
            right.push(num);
            int top = right.top();
            right.pop();
            left.push(top);
        } else {
            left.push(num);
            int top = left.top();
            left.pop();
            right.push(top);
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()){
            return (left.top() + right.top() + 0.0)/2;
        }
        return left.top();
    }
};
