class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> newIntervals;
        newIntervals.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
        {
            if(newIntervals.back()[1] >= intervals[i][0])
                newIntervals.back()[1] = max(newIntervals.back()[1], intervals[i][1]);
            else
                newIntervals.push_back(intervals[i]);
        }
        return newIntervals;
    }
};