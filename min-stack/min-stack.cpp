class MinStack {
public:
    map<int, int> Map;
    stack<int> st;
    MinStack() { }
    
    void push(int val) {
        st.push(val);
        Map[val]++;
    }
    
    void pop() {
        int top = st.top(); st.pop();
        Map[top]--;
        if(Map[top] == 0) Map.erase(top);
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return Map.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */