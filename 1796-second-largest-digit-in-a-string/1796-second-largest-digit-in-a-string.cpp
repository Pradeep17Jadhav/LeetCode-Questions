class Solution {
public:
    int secondHighest(string s) {
        // return usingHashVector(s);
        return withoutExtraSpace(s);
    }
    
    //Time - O(N), Space - O(1)
    int withoutExtraSpace(string &s)
    {
        int last = -1;
        int secondLast = -1;
        
        for(char &c:s)
        {
            if(c >= '0' and c <= '9')
            {
                if(last < c - '0')
                {
                    secondLast = last;
                    last = c - '0';
                }
                else if(last >  c - '0' and secondLast < c - '0')
                    secondLast = c - '0';
            }
        }
        return secondLast;
    }

    //Time - O(N + 10), Space - O(1)
    int usingHashVector(string &s)
    {
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