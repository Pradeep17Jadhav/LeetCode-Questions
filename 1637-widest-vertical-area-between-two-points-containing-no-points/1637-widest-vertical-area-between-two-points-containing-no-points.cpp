class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int>arrX;
        for(auto &v: points)
        {
            arrX.insert(v[0]);
        }
        int maxDiff = 0;
        set<int>::iterator itr = next(arrX.begin()); //we can use "auto itr = next(arrX.begin());" as well
        for(; itr != arrX.end(); itr++)
        {
            maxDiff = max(maxDiff, *itr - *prev(itr));
        }
        return maxDiff;
    }
};