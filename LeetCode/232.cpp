class MyQueue {
    int fr;
    stack<int> pr, aux;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(pr.empty()){fr = x;}
        pr.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!pr.empty()){
            aux.push(pr.top());
            pr.pop();
        }
        int x= aux.top();
        aux.pop();
        if(!aux.empty()){fr = aux.top();}
        while(!aux.empty()){
            pr.push(aux.top());
            aux.pop();
        }
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return fr;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return pr.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */