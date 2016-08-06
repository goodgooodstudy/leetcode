class Stack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(q1.size() == 0) return;
        while(q1.size()!=1){
            int cur = q1.front();
            q1.pop();
            q2.push(cur);
        }
        q1.pop();
        queue<int> tmp = q2;
        q2 = q1;
        q1 = tmp;
        
    }

    // Get the top element.
    int top() {
        if(q1.size() == 0) return 0;
        int cur;
        while(q1.size()!=0){
            cur = q1.front();
            q1.pop();
            q2.push(cur);
        }

        queue<int> tmp = q2;
        q2 = q1;
        q1 = tmp;
        return cur;
        
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
        
    }
};
