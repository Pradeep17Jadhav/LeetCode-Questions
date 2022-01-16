class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        vector<int> chars(26, -1);
        int searchIndex = 0;
        int maxIndex = -1;
        int start = 0;
        
        //store max index position of each alphabet
        for(int i = 0; i < s.size(); i++)
        {
            chars[s[i] - 'a'] = i;
        }

        //iterate each alphabet and find max index for each char
        for(int i = 0; i < s.size(); i++)
        {
            maxIndex = max(maxIndex, chars[s[i] - 'a']);
            
            //if max char matches to the current index then make a partition to the next index
            if(maxIndex == i)
            {
                res.push_back(i - start + 1);
                start = searchIndex = i + 1;
            }
        }
        
        return res;
    }
};