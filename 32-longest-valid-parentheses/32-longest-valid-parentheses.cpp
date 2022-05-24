class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int curr = 0;
        stack<int> st;
        
        //initialize stack as ')' so it can be potential end of valid string. 
        //the next index might be the start of valid parentheses string
        st.push(-1); 

        //for each element, keep track of the last index at which parantheses is invalid
        //keep on adding opening bracket index in the stack and removing the same 
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();
                
                //stack will become empty only when we have an extra ')' bracket.
                //so we cannot have any further longest string having current index. 
                //add it in a stack so it will now work as end of last valid parentheses string
                //now, its next index might be the start of valid parentheses string
                if (st.empty()) {
                    st.push(i);
                    
                } 
                //if stack isnt empty, it means the current closing bracket is part of valid parantheses. 
                //so recompute longest sequence size
                else {
                    res = max(res, i - st.top());
                }
            }
        }
        return res;
    }
};
