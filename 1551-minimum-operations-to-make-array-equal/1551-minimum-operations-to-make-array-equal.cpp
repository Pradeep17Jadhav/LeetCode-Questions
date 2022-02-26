class Solution {
public:
    int minOperations(int n) {
        // return solution1(n);
        return solution2(n);

    }
    
    //TC:O(1)
    int solution2(int &n)
    {
        //consider array 1 3 5 7 9 11 13 15 17.
        //mid is 9, so req operations are 8 6 4 2 (both subtr & add included in 1 operation)
        //hence we have to find sum of Arithmetic progression

        int N;
        if(n & 1) //bitwise operator to check odd num
        {
            N = (n-1)/2;
            return N * (N+1);
        }

        N = n/2;
        return N * N;
    }
    
    //TC: O(N)
    //TLE
    int solution1(int &n)
    {
        vector<int>nums;
        for(int i = 0; i < n; i++)
            nums.push_back((2 * i) + 1);
        
        int i = 0;
        int j = nums.size() - 1;
        int res = 0;
        while(i < j)
        {
            if(nums[i] < nums[j])
            {
                nums[i]++;
                nums[j]--;
                res++;
            }
            else
            {
                i++;
                j--;
            }
        }
        return res;
    }
};