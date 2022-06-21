class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int res = 0;
        priority_queue<int> pq;
        for(int i = 1; i < heights.size(); i++) {
            if(heights[i] > heights[i-1]) {
                int diff = heights[i] - heights[i-1];
                if(bricks >= diff) {
                    pq.push(heights[i] - heights[i-1]);
                    bricks -= diff;
                }
                else if(ladders) {
                    if(pq.size() && pq.top() >= diff) {
                        bricks += pq.top();
                        pq.pop();
                        ladders--;
                        i--;
                        continue;
                    }
                    ladders--;
                } 
                else
                    break;
                
            }
            res = i;
        }
        return res;
    }
};