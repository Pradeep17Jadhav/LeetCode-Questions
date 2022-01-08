class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return 0;
        sort(intervals.begin(), intervals.end());
        int prev = 0;
        int count = 0;
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[prev][1] > intervals[i][0])
            {
                count++;
                if(intervals[i][1] < intervals[prev][1])
                    prev = i;
            }
            else
                prev = i;
                
        }
                    
        // return intervals.size() - newList.size();
        return count;
    }
};