class MinStack {
    stack<pair<int, int>> st;
    int smin = 0;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push({val, 0});
            smin = val;
        }
        else {
            st.push({val, smin});
            smin = min(smin, val);
        }
    }
    
    void pop() {
        smin = st.top().second;
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return smin;
    }
};
