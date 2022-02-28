class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        int start, end;
        
        for(int i = 0; i < nums.size(); i++)
        {
            //assign current value to "start" and move to next index
            start = nums[i++];
            
            //skip index if current value equals to previous value + 1
            while(i < nums.size() && nums[i] == nums[i-1]+1) 
                i++;

            //mark end index value as end value. 
            //note that index is decremented as end value is got incremented in while loop
            end = nums[--i]; 
            
            //since gap is found between numbers, add it to result
            if(start == end)
                res.push_back(to_string(start));
            else
                res.push_back(to_string(start) + "->" + to_string(end));
        }
        return res;
    }
};