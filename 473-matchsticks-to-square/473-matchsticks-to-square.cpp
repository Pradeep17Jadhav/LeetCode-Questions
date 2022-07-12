class Solution {
public:
    bool makesquare(vector<int>& sticks) {
        int n = sticks.size();
        int total = 0;
        for(int i: sticks)
            total += i;
        if(total % 2 == 1 || n < 4)
            return false;

        int side = total / 4;
        sort(sticks.begin(), sticks.end());
        return traverse(sticks, n-1, side, side, side, side);
    }
    
    bool traverse(vector<int>& sticks, int index, int a, int b, int c, int d) {
        if(index == -1)
            return a == 0 && b == 0 && c == 0 && d == 0;

        if(sticks[index] <= a && traverse(sticks, index-1, a-sticks[index], b, c, d))
            return true;
        if(sticks[index] <= b && traverse(sticks, index-1, a, b-sticks[index], c, d))
            return true;
        if(sticks[index] <= c && traverse(sticks, index-1, a, b, c-sticks[index], d))
            return true;
        if(sticks[index] <= d && traverse(sticks, index-1, a, b, c, d-sticks[index]))
            return true;
        
        return false;
    }
};