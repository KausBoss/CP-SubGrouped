class MinStack {
    vector<int> v;
    vector<int> minval;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if(minval.empty() || minval.back() >= x){
            minval.push_back(x);
        }
        v.push_back(x);
    }
    
    void pop() {
        if(minval.back() == v.back()){
            minval.pop_back();
        }
        v.pop_back();
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return minval.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */