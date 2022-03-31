class Solution {
public:
    //Reference - https://www.youtube.com/watch?v=wLXMu_XJnLo
    //We will use "binary search on answer" for this problem
    //the minimum answer for this problem can be the number which is maximum in array
    //example - [2,3,4] - 2 and 3 cannot be ans as 4 alone will always be maximum
    //the maximum answer cannot be greater than sum of all elements in array
    //so we apply binary search betweek this left and right range to reach the answer
    //each time we find possible mid and check if given number of partitions are possible or not
    //if possible, the answer can also be smaller than current mid, so we reduce the range end to mid-1
    //if not possible, the answer can be greater than current mid, so we increase range start to mid+1
    
    int splitArray(vector<int>& nums, int m) {
        int l, r, res, mid;
        l = r = mid = res = 0;
        for(int &i: nums)
        {
            l = max(l, i); //use maximum number from array as left
            r += i; //use sum of all elements as right
        }
        while(l <= r)
        {
            mid = (l+r)/2;
            if(CountPartitions(nums, mid) <= m) //check if 'm' partitions are possible with current mid
                res = mid, r = mid-1; //if yes, reduce the range from right
            else
                l = mid+1; //if not, reduce the range from left
        }
        return res;
    }
    
    //find the minimum partitions in which the given nums arrays can be split into for the maxSum
    int CountPartitions(vector<int>& nums, int maxSum) {
        int sum = 0;
        int partitions = 1; //include the last partition
        for(int &i: nums)
        {
            sum += i;
            if(sum > maxSum)
                partitions++, sum = i;
        }
        return partitions; 
    }
};