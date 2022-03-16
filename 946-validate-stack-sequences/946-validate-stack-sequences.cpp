class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        return solution1(pushed, popped);
        // return solution2(pushed, popped);
    }
    
    //using popped as a stack
    //TC: O(N)
    //SC: O(1) extra space, O(N) modified space
    bool solution1(vector<int>& pushed, vector<int>& popped)
    {
        int i = 0;
        int j = 0;
        for(int &val: pushed)
        {
            pushed[i] = val;
            while(i >= 0 && pushed[i] == popped[j])
            {
                i--;
                j++;
            }
            i++;
        }
        
        return i == 0;
    }

    //using extra stack
    //TC: O(N)
    //SC: O(N)
    bool solution2(vector<int>& pushed, vector<int>& popped)
    {
        vector<int>stack;
        for(int i = 0, j = 0; i < pushed.size(); i++)
        {
            stack.push_back(pushed[i]);
            while(!stack.empty() && stack.back() == popped[j])
            {
                stack.pop_back();
                j++;
            }
        }
        return stack.empty();
    }
};