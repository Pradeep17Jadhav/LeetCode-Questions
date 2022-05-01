class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string tempS = "";
        string tempT = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '#' && tempS.size())
                tempS.pop_back();
            
            if(s[i] != '#')
                tempS.push_back(s[i]);
        }
        
        for(int i = 0; i < t.size(); i++)
        {
            if(t[i] == '#' && tempT.size())
                tempT.pop_back();
            
            if(t[i] != '#')
                tempT.push_back(t[i]);
        }

        return tempS == tempT;
    }
};