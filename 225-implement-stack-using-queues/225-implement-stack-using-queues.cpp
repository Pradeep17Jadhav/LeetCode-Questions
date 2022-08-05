class MyStack {
public:
    queue<int> q;
    int peek = -1;

    MyStack() {
    }
    
    void push(int x) {
        peek = x;
        q.push(x);
    }
    
    int pop() {
        int n = q.size();
        if(n == 0)
            return -1;
        int temp;
        while(--n)
        {
            temp = q.front();
            q.pop();
            q.push(temp);
        }
        temp = q.front();
        q.pop();
        peek = q.back();
        return temp;
    }
    
    int top() {
        return peek;
    }
    
    bool empty() {
        return q.empty();
    }
};