class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>seq;
        int curr;
        for(int i = 1; i <= 9; i++)
        {
            curr = i; 
            for(int j = i + 1; j <= 9; j++)
            {
                curr = curr  * 10 + j;
                if(curr > high) break;
                if(curr >= low) seq.push_back(curr);
            }
        }
        sort(seq.begin(), seq.end());
        return seq;
    }
};