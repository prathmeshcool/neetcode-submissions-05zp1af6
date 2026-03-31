class MinStack {
private:
        stack<int>st;
        stack<int>min_stk;
        
public:
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        val = min(val,min_stk.empty()?val:min_stk.top());
        min_stk.push(val);
    }
    
    void pop() {
        st.pop();
        min_stk.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};
