class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
//         vector<int>low (26, s.size());
//         vector<int>high (26, -1);
        
//         for(int i = 0; i < s.size(); i++)
//         {
//             low[s[i] - 'a'] = min(low[s[i] - 'a'], i);
//             high[s[i] - 'a'] = max(high[i], i);
            
//         }      
        
//         int maxDiff = -1;
//         for(int i = 0; i < 26; i++)
//         {
//             if(high[i] != -1)
//             {
//                 maxDiff = max(maxDiff, high[i] - low[i] - 1);
//             }
                
//         }
//         return maxDiff;
        
        vector<int> index(26, -1);
        int res = -1;
        for(int i = 0; i < s.size(); i++)
        {
            if(index[s[i] - 'a'] == -1)
                index[s[i] - 'a'] = i;
            res = max(res, i - index[s[i] - 'a'] - 1);
        }
        return res;
    }
};