#include<algorithm>
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max = 0;
        int currMax = 0;
        for(string sent:sentences)
        {
            for(auto w:sent)
            {
                if(w == ' ')
                    currMax++;
            }
            max = std::max(max, ++currMax);
            currMax = 0;
        }
        return max;
    }
};