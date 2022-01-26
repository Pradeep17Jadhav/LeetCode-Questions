class Solution {
public:
    int secondHighest(string s) {
        vector<bool>hash(10, false);
        for(char &c:s)
        {
            if(isdigit(c))
                hash[c - '0'] = true;
        }
        bool isFirst = true;
        for(int i = hash.size() - 1; i >= 0; i--)
        {
            if(hash[i])
            {
                if(isFirst)
                    isFirst = false;
                else
                    return i;    
            }
        }
        return -1;
    }
};