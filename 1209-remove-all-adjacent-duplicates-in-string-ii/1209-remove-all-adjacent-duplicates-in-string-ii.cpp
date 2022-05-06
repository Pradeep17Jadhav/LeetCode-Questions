class Solution {
public:
    string removeDuplicates(string s, int k) {
        //for each char, maintain the count of consecutive chars using a pair
        vector<pair<int, char>> stack = {{0, '#'}}; //init with dummy data with count 0
        for(char c: s) 
        {
            //if prev char is not same is current, add new char to stack with consecutive count 1
            if(stack.back().second != c) 
            {
                stack.push_back({1, c});
            }
            else 
            { 
                stack.back().first++; //increment consecutive count if curr char and prev char are equal
                if(stack.back().first == k) //if required consecutive counts are met, remove the element from stack as we dont need it
                    stack.pop_back();
            }
        }
        string res;
        for(auto &p: stack) 
        {
            res.append(p.first, p.second); //append the char for the consecutive count number of time
        }
        
        return res;
    }

};
