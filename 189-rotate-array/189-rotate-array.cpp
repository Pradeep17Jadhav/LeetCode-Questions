class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(!k) return;
        solution2(nums, k);
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
    
    void solution2(vector<int>& nums, int k) {

        int temp;
        int n = nums.size();
        int start = 0;
    
        //keep on swaping the first k numbers with last k numbers
        //keep on increasing the 'first' index as for each iteration, first k numbers will get placed to correct position
        //and the 'n', which stands for remaining elements to be rotated, will keep on decreasing by 'k'
        //k will become 0 when all numbers are rotated
        while(k)
        {
            k = k % n;
            
            //swap numbers 'k' times from 'start' index, with the last 'k' indices
            for (int i = 0; i < k; i++)
                swap(nums[start + i], nums[start + n - k + i]);
            
            // Example -
            // Iteration 0 - [0,1,2,3,4,5,6,7,8,9], original array for k=3
            // Iteration 1 - [7,8,9,3,4,5,6,0,1,2], when start = 0, n = 10
            // Iteration 2 - [7,8,9,0,1,2,6,3,4,5], when start = 3, n = 7
            // Iteration 3 - [7,8,9,0,1,2,3,4,5,6], when start = 6, n = 4
            
            n = n - k;
            start = start + k;

        }
        
        // MORE DRY RUNS
        // Iteration 0 - [1,2,3,4,5,6,7], original array for k=3
        // Iteration 1 - [5,6,7,4,1,2,3], when start = 0, n = 7
        // Iteration 2 - [5,6,7,1,2,3,4], when start = 3, n = 4
        
        
        
        // Iteration 0 - [0,1,2,3,4,5,6,7,8,9], original array for k=4
        // Iteration 1 - [6,7,8,9,4,5,0,1,2,3], when start = 0, n = 10
        // Iteration 2 - [6,7,8,9,0,1,2,3,4,5], when start = 4, n = 6
    }
};