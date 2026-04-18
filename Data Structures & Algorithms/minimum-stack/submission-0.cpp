class MinStack {
    stack<pair<int,int>> stk; // {og, min}
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.size() == 0){
            stk.push({val, val});
        } else {
            auto top = stk.top();
            if(top.second > val){
                // fonud a new min
                stk.push({val, val});
            } else {
                stk.push({val, top.second});
            }
        }
    }
    
    void pop() {
        if(stk.size() > 0 ){
            stk.pop();
        }
    }
    
    int top() {
        auto top = stk.top();
        return top.first;
    }
    
    int getMin() {
        auto top = stk.top();
        return top.second;
    }
};
