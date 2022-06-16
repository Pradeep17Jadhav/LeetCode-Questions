class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReachable = 0; //maximum index we can reach using the jumps available at all explored indices including current i
        int lastJumpedPos = 0; //the index to which we can jump using the index from which we last jumped
        int jumps = 0;
        
        for(int i = 0; i < nums.size()-1; i++)
        { 
            //keep on finding the maximum index to which we can jump
            //once we complete a jump, update the maximum jump index for next jump
            maxReachable = max(maxReachable, i + nums[i]);
            if(i == lastJumpedPos) 
            {
                lastJumpedPos = maxReachable;
                jumps++;
            }
        }
        return jumps;
    }
};