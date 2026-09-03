class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        mini=LLONG_MAX;
    }
    
    void push(int value) 
    {
        long long x=value;
        if(st.empty())
        {
            st.push(x);
            mini=x;
        }
    
        else if(x<mini)
        {
            long long e=(2*x)-mini;
            st.push(e);
            mini=x;
        }
        else
        {
            st.push(x);
        }
    }
    
    void pop() {
        if(st.top()<mini)
        { 
        mini=(2*mini)-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<mini)
        {
        return mini; 
        }
    
        return st.top();
    }
    
    int getMin() {
         return mini; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */