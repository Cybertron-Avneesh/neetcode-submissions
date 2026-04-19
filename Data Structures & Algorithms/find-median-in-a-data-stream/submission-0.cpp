class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> left;
    priority_queue<int> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size() == right.size()){
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
            return (double)(left.top() + right.top()) / 2.0;
        }
        return left.top();
    }
};
