class Solution {
public:
    //Intuition -
    //There are limited bricks and ladders
    //But one ladder can be used to cross a huge gap in height
    //So we should only use ladder for the biggest height differences
    //Initially We will start using only bricks till they are exhausted
    //We can use priority queue to keep track of differences of heights where bricks are used
    //Once bricks are exhausted, we will replace the greatest difference with a single ladder and add bricks used there to remaining bricks.
    //Continue this till all ladders are exhausted and also the bricks are insufficient
    
    //TC: O(N)
    //SC: O(N) for PQ
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int res = 0;
        priority_queue<int> pq;
        for(int i = 1; i < heights.size(); i++) {
            //if we need to jump higher
            if(heights[i] > heights[i-1]) {
                int diff = heights[i] - heights[i-1]; //total bricks needed
                
                //if we have required bricks, use them and add the quantity in PQ
                if(bricks >= diff) {
                    pq.push(heights[i] - heights[i-1]);
                    bricks -= diff;
                }
                
                //if bricks are exhausted but ladders are available
                else if(ladders) {
                    //if the heighest total number of bricks used is sufficient for current difference
                    if(pq.size() && pq.top() >= diff) {
                        bricks += pq.top();
                        pq.pop();
                        ladders--;
                        i--;
                        continue;
                    }
                    //if the heighest total number of bricks used cannot be used to replace current requirement
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