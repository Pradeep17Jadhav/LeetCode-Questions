class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return backspaceCompare_1(s, t);
        // return backspaceCompare_2(s, t);
    }

    //TC: O(s+t) = O(N)
    //SC: O(1)
    bool backspaceCompare_1(string s, string t) {
        int ptrS = 0;
        int ptrT = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != '#')
                s[ptrS++] = s[i];
            else if(ptrS)
                ptrS--;
        }
        
        for(int i = 0; i < t.size(); i++)
        {
            if(t[i] != '#')
                t[ptrT++] = t[i];
            else if(ptrT)
                ptrT--;
        }
        return s.substr(0, ptrS) == t.substr(0, ptrT);
    }

    //TC: O(s+t) = O(N)
    //SC: O(s+t) = O(N)
    bool backspaceCompare_2(string s, string t) {
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