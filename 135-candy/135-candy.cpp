class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        //give everyone atleast 1 candy
        vector<int> left(n, 1); //to check if left student has greater rating
        vector<int> right(n, 1); //to check if right student has greater rating
        
        //check if left child has greater rating. if yes then give extra candy to current child
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i-1])
                left[i] = left[i-1] + 1;
        }
        
        //check if right child has greater rating. if yes then give extra candy to current child
        for(int i = n-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1])
                right[i] = right[i+1] + 1;
        }
        
        //take maximum candy considering both left and right neighbors
        int total = 0;
        for(int i = 0; i < n; i++) {
            total+= max(left[i], right[i]);
        }
        
        return total;
    }
};