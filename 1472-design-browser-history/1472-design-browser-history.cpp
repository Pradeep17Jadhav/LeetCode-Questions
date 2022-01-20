class BrowserHistory {
    int i = 0;
    vector<string> browser;
public:
    BrowserHistory(string homepage) {
        i++;
        browser.push_back(homepage);
    }
    

    void visit(string url) {
        i++;
        browser.resize(i);
        browser[i - 1] = url;
    }
    
    //push curr urls to next stack, make curr url as top of prev stack
    string back(int steps) {
        if(steps >= i)
        {
            i = 1;
            return browser[0];
        }
        i -= steps;
        return browser[i - 1]; //0 1 2 3 i=4 5 6
    }
    
    //push curr url in next stack, make curr url as top of next stack
    string forward(int steps) {
        if(i + steps > browser.size())
        {
            i = browser.size();
            return browser[i - 1];
        }
        
        i += steps;
        return browser[i - 1];
    }
};

// class BrowserHistory {
//     stack<string>prev; // store previous urls
//     stack<string>next; // store next urls
//     string curr; //store current url
// public:
//     BrowserHistory(string homepage) {
//         curr = homepage;
//     }
    
//     //push curr url in prev stack, update curr url, empty front stack
//     void visit(string url) {
//         prev.push(curr);
//         curr = url;
//         next = stack<string>(); //empty front stack
//     }
    
//     //push curr urls to next stack, make curr url as top of prev stack
//     string back(int steps) {
//         while(steps-- and !prev.empty())
//         {
//             next.push(curr);
//             curr = prev.top();
//             prev.pop();
//         }
//         return curr;
//     }
    
//     //push curr url in next stack, make curr url as top of next stack
//     string forward(int steps) {
//         while(steps-- and !next.empty())
//         {
//             prev.push(curr);
//             curr = next.top();
//             next.pop();
//         }
//         return curr;
//     }
// };


/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */