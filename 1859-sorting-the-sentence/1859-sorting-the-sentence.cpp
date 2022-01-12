class Solution {
public:
    string sortSentence(string s) {
        // return sortSentenceUsingMap(s);
        return sortSentenceUsingVector(s);
    }
    
    string sortSentenceUsingVector(string &s)
    {
        //since numbers of words are from 1 to 9
        vector<string> res(9);
        
        //to save starting index of current word
        int start = 0; 
        
        for(int i = 1; i < s.size(); i++)
        {
            //keep loop running till we find a number
            if(isdigit(s[i]))
            {
                //add substring from s[start] to s[i-1] index in map with key s[i]
                res[s[i] - '0' - 1] = s.substr(start, i - start);
                
                //skip next char as it will be a space
                i++;
                
                //update start index for next word
                start = i + 1;
            }
        }
        
        string ans = "";
        for(string i:res)
        {
            if(i.size())
                ans += i + " ";
        }
        ans.pop_back();
        return ans;
    }
        
    string sortSentenceUsingMap(string &s)
    {
        string res;
        
        //to save starting index of current word
        int start = 0; 
        map<int, string> m;

        for(int i = 1; i < s.size(); i++)
        {
            //keep loop running till we find a number
            if(isdigit(s[i]))
            {
                //add substring from s[start] to s[i-1] index in map with key s[i]
                m[s[i]] = s.substr(start, i - start);
                
                //skip next char as it will be a space
                i++;
                
                //update start index for next word
                start = i + 1;
            }
        }
        
        //since map is sorted, we will concat the values for keys 1,2,3,....,n
        for(auto i:m)
        {
            res += i.second + " ";
        }
        
        //remove the space after last word and return
        return res.substr(0, res.size() - 1);
    }
};