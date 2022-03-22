class Solution {
public:
    string getSmallestString(int n, int k) {
        return solution1(n, k);
        // return solution2(n, k);
    }

    string solution1(int &n, int &k)
    {        
        string s = string(n, 'a'); //initialize string with 'a's
        k -= n; //n*'a' are used so subtract it from k
        
        //now we do not care of filling up 'a's. Just fill from end the maximum available K.
        while(k > 0)
        {
            s[--n] += min(25, k);
            k -= min(25, k);
        }
        return s;
    }
    
    string solution2(int &n, int &k)
    {
        string s = "";
        for(int i = n - 1; i >= 0; i--)
        {
            int val = min(26, k-i);
            s.push_back(val + 'a' - 1);
            k = k - val;
        }
        
        reverse(s.begin(), s.end());
        return s;
    }
};