class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 1);
        
        for(int i = 0; i <= rowIndex; i++) {
            int prev = res[0]; //since with each jth iteration, we have to update the res[j], so for next iteration we need to preserve current value of res[j]
            for(int j = 1; j < i; j++) {
                int temp = res[j];
                res[j] = prev + res[j];
                prev = temp;
            }
        }
        
        return res;
    }
};