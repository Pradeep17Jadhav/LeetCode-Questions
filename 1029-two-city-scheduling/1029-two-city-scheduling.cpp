class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int cost = 0;
        vector<int> refund;
        for(auto &v: costs) {
            cost += v[0]; //first send everyone to city A
            refund.push_back(v[1] - v[0]); //find the refund if we send ith person to city B     
        }

        sort(refund.begin(), refund.end());
        for(int i = 0; i < refund.size()/2; i++)
            cost += refund[i];          

        return cost;
        
    }
};