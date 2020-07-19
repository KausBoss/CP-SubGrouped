class MyStack {
    queue<int> q;
    int upar;
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        upar=x;
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size=q.size();
        for(int i=1; i<size; i++){
            int temp=q.front();
            if(i == size-1){upar = temp;}
            q.pop();
            q.push(temp);
        }
        q.pop();
    }
    
    /** Get the top element. */
    int top() {
        return upar;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty(); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */