class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        //dp based question      
        //matrix for dp
        double dp[101][101] = {0.0};
    
        // the first glass will always be poured first
        dp[0][0] = poured;
    
        //iterate rows
        for(int i = 0; i <= query_row; i++)
        {
            //iterate columns
            for(int j = 0; j <= query_glass; j++)
            {
                //if cups to be poured in > 1, it will be spilled
                if(dp[i][j] >= 1)
                {
                    //handle spilled champagne for next row,
                    //will be spilled on current and next glass

                    dp[i + 1][j] += (dp[i][j] - 1) / 2.0; //left glass
                    dp[i + 1][j + 1] += (dp[i][j] - 1) / 2.0; //right glass
                    dp[i][j] = 1; //excess is now spilled, curr glass will have 1 cup champgn
                }
            }
        }
        return dp[query_row][query_glass]; //champagne accumulated at required index;
    }
};