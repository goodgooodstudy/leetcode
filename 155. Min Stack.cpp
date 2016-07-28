class MinStack {
private:
        stack<int> data;
        stack<int> m;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(m.empty()||x <= getMin())m.push(x);
        data.push(x);
        
    }
    
    void pop() {
        if(data.top() == getMin()) m.pop();
        data.pop();
        
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return m.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
