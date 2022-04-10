class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        solution1(nums, k) ;
    }
    
    void solution1(vector<int>& nums, int k) {
        //suppose question is //[0 1 2 3 4 5 6 7 8 9 10], k=3
        
        //reverse the 0 to n-k array
        //nums become [7 6 5 4 3 2 1 0 8 9 10]
        reverse(nums.begin(), nums.end()-k);
        
        //reverse n-k to n array
        //nums become [7 6 5 4 3 2 1 0 10 9 8]
        reverse(nums.end()-k, nums.end());
        
        
        //reverse the whole array
        //nums become [8 9 10 0 1 2 3 4 5 6 7] which is the answer
        reverse(nums.begin(), nums.end());
    }
};