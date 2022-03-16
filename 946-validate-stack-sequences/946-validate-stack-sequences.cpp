class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // return solution1(pushed, popped);
        return solution2(pushed, popped);
    }
    
    //using popped as a stack
    //TC: O(N)
    //SC: O(1) extra space, O(N) modified space
    bool solution1(vector<int>& pushed, vector<int>& popped)
    {
        int i = 0;
        int j = 0;
        int k = pushed.size() - 1;
        while(i < pushed.size() || j < popped.size())
        {
            if(i >= pushed.size())
            {
                while(pushed[k] == -1)
                    k--;
                if(pushed[k] == popped[j])
                {
                    k--;
                    j++;
                }
                else return false;
            }
            else if(pushed[i] < popped[j])
                i++;
            else if(pushed[i] == popped[j])
            {
                pushed[i] = -1;
                i++;
                j++;
            }
            else return false;
        }
        return true;
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