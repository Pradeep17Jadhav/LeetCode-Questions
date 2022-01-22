class Solution {
public:
    string removeDuplicates(string s) {
        //use a string stack to store values
        string stack = "";
        for(char &c:s)
        {
            //if back of string is equal to current, remove back and skip current
            if(!stack.empty() and c == stack.back())
            {
                stack.pop_back();
            }
            else
            {
                stack.push_back(c);
            }
        }
        return stack;
    }
};