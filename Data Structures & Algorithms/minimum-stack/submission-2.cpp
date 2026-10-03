class MinStack {
public:
    stack<int> st;
    stack<int> minst;

    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if(minst.empty())
            minst.push(val);
        else
            minst.push(min(minst.top(), val));
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.empty() ? -1 : st.top();
    }
    
    int getMin() {
        return minst.empty() ? -1 : minst.top();
    }
};
