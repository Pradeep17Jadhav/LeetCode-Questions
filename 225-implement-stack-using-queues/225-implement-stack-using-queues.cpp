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
        int temp;
        while(n--)
        {
            temp = q.front();
            q.pop();
            if(temp == peek)
            {
                peek = q.back();
                return temp;
            }
            else
                q.push(temp);
        }
        return -1;
    }
    
    int top() {
        return peek;
    }
    
    bool empty() {
        return q.empty();
    }
};