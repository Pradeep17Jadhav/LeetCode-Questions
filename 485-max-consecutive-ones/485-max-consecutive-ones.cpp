class Solution {
public:
    //can be solved with 2 methods
    //1 - sliding window
    //2 - counting max of consecutives
    
    //i am using method 2
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxx = 0;
        int curr = 0;
        
        for(int &i: nums)
        {
            if(i)
            {
                curr++;
                maxx = max(maxx, curr);
            }
            else if(curr)
                curr = 0;
        }
        
        return maxx;
    }
};