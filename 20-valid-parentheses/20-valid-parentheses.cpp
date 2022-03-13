#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(auto i:s)
        {
            if(i == '(' or i == '[' or i == '{')
                stack.push(i);
            else
            {
                if(stack.empty())
                    return false;
                
                if(stack.top() == '(' and i == ')' or
                  stack.top() == '{' and i == '}' or
                  stack.top() == '[' and i == ']')
                    stack.pop();
                else
                    return false;
            }
        }

        return stack.empty();
    }    
};