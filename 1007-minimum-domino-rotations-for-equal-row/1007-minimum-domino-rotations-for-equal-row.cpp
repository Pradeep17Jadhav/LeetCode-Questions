class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        //we just need to check if there is a number which is common in all index of tops or bottoms
        //we can chose any random set of [top, bottom] so we use 0th index
        //first use tops[0] as target and use minimum miss counts as answer
        //if tops[0] is absent, use bottoms[0] as new target

        int target = tops[0];
        int n = tops.size();
        int topMiss = 0;
        int bottomMiss = 0;
        for(int i = 0; i < n; i++)
        {
            if(target != tops[i] && target != bottoms[i])
                break;

            if(tops[i] != target)
                topMiss++;

            if(bottoms[i] != target)
                bottomMiss++;

            if(i == n-1)
                return min(topMiss, bottomMiss);
        }
        target = bottoms[0];
        topMiss = 0;
        bottomMiss = 0;
        for(int i = 0; i < n; i++)
        {
            if(target != tops[i] && target != bottoms[i])
                break;

            if(tops[i] != target)
                topMiss++;

            if(bottoms[i] != target)
                bottomMiss++;

            if(i == n-1)
                return min(topMiss, bottomMiss);
        }
        return -1;
    }
};