class MinStack {
    stack<pair<int,int>> stk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.size()){
            auto top = stk.top();
            stk.push({val, min(top.second, val)});
        } else {
            stk.push({val, val});
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};
