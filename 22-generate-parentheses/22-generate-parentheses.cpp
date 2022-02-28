class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        getParantheses("", n, 0);
        return res;
    }
    
    void getParantheses(string s, int left, int right)
    {
        //terminate when all left and right paranthese are added
        if(left == 0 && right == 0)
        {
            res.push_back(s);
            return;
        }
        
        //if left parantheses if available, also increase right as left needs to be closed
        if(left > 0)
            getParantheses(s+"(", left - 1, right + 1);
        
        //add right parantheses if available. Left paratheses doesnt depend on right
        if(right > 0)
            getParantheses(s+")", left, right - 1);
    }
};