class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> stack;
        int count = 0;
        int score = 0;
        for(char c: s)
        {
            if(c == '(')
            {
                stack.push_back(score);
                score = 0;
            }
            else
            {
                score = stack.back() + max(score * 2, 1);
                stack.pop_back();
            }
        }
        return score;
    }
};