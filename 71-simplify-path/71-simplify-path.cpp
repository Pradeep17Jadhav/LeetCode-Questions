class Solution {
public:
    string simplifyPath(string path) {
        string res, curr;
        vector<string>stack;
        stringstream ss(path);
        
        while(getline(ss, curr, '/'))
        {
            if(curr == "" || curr == ".") //ignore double slash // and same directory /./
                continue;

            if(curr != "..") //go back to previous directory, so pop the last foldername
                stack.push_back(curr);
    
            else if(!stack.empty()) //go back to prev folder, do nothing if already in root
                stack.pop_back();
        }
        
        //make string from all folders in the stack
        for(auto &c: stack)
        {
            res += "/" + c;
        }
        
        return res.empty() ? "/" : res;
    }
};