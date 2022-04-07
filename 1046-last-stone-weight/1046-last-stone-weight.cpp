class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int i = 0;
        int j = 1;
        
        while(stones.size())
        {
            if(stones.size() == 1)
                return stones[0];
            sort(stones.begin(), stones.end());
            if(stones[stones.size()-1] == stones[stones.size()-2])
            {
                stones.pop_back();
            }
            else
            {
                stones[stones.size()-2] = stones[stones.size()-1] - stones[stones.size()-2];
            }
            stones.pop_back();
        }
        return 0;
    }
};