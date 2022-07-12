class Solution {
public:
    bool makesquare(vector<int>& sticks) {
        int n = sticks.size();
        int total = accumulate(sticks.begin(), sticks.end(), 0);
        if(total % 2 || n < 4) //odd sum cannot give a square, and we need atleast 4 matchsticks
            return false;

        int side = total/4;
        sort(sticks.begin(), sticks.end()); //start with largest sticks first to avoid unnecessary recursive calls
        return traverse(sticks, n-1, side, side, side, side); //starting with last index (can also start from first index)
    }
    
    bool traverse(vector<int>& sticks, int index, int a, int b, int c, int d) {
        if(index == -1) //after traversing the whole array, if all sides become 0 then we can create a square from matchsticks
            return a == 0 && b == 0 && c == 0 && d == 0;

		//try putting the current (index'th) matchstick in all four sides.
		//make sure that current stick is equal or smaller than remaining length
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