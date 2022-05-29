class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) 
            return intervals;
        
        //sort by 0-index element of all intervals
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        res.push_back(intervals[0]); //first interval will always be there is result as it has lowest starting range

        for(int i = 1; i < intervals.size(); i++)
        {
            //check if end-range of last interval in result is greater or equal to start-range of current interval
            //if yes, then update the end-range of last interval
            //if not, then the previous interval has ended so add current interval to res as a new interval
            if(res.back()[1] >= intervals[i][0])
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};