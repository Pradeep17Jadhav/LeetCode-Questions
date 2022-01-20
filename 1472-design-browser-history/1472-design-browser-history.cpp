class BrowserHistory {
    stack<string>prev; // store previous urls
    stack<string>next; // store next urls
    string curr; //store current url
public:
    BrowserHistory(string homepage) {
        curr = homepage;
    }
    
    //push curr url in prev stack, update curr url, empty front stack
    void visit(string url) {
        prev.push(curr);
        curr = url;
        next = stack<string>(); //empty front stack
    }
    
    //push curr urls to next stack, make curr url as top of prev stack
    string back(int steps) {
        while(steps-- and !prev.empty())
        {
            next.push(curr);
            curr = prev.top();
            prev.pop();
        }
        return curr;
    }
    
    //push curr url in next stack, make curr url as top of next stack
    string forward(int steps) {
        while(steps-- and !next.empty())
        {
            prev.push(curr);
            curr = next.top();
            next.pop();
        }
        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */