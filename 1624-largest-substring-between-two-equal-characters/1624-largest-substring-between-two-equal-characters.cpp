class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
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