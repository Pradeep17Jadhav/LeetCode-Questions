class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<bool>hash(26);
        vector<bool>caphash(26);
        int res = 0;
        
        for(char &c: jewels)
        {
            if(isupper(c))
                caphash[c - 'A'] = true;
            else
                hash[c - 'a'] = true;
        }
            
        
        for(char &c: stones)
        {
            if(isupper(c) and caphash[c - 'A'])
                res++;
            else if(islower(c) and hash[c - 'a'])
                res++;
        }
        return res;
    }
};