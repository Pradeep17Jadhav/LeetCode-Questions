class Solution {
public:
    static bool compare(vector<int>& a, vector<int> & b)
    {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int units = 0;
        for(vector<int> &boxType : boxTypes) {
            int minimumBoxes = min(boxType[0], truckSize);
            units += minimumBoxes * boxType[1];
            truckSize -= minimumBoxes;
            if(truckSize <= 0)
                break;
        }
        
        return units;
    }
};