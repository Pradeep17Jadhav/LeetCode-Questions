class CustomStack {
public:
    int mx = 0;
    vector<int> st;
    CustomStack(int maxSize) {
        mx = maxSize;
    }
    
    void push(int x) {
        if(st.size() < mx)
            st.push_back(x);
    }
    
    int pop() {
        int top = -1;
        if(st.size())
        {
            top = st.back();
            st.pop_back();
        }
        return top;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < st.size(); i++, k--)
        {
            if(!k) break;
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */