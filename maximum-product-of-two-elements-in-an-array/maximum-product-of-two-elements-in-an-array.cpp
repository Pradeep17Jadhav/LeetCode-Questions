class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
//         Solution 1
//         int greatest = 0;
//         int great = 0;
//         for(int i = 1; i < nums.size(); i++)
//         {
//             if(nums[i] > nums[greatest])
//             {
//                 if(i > 1)
//                     great = greatest;
//                 greatest = i;
//             }
//             else if(nums[i] > nums[great] or great == greatest)
//                 great = i;
//         }
        
//         return (nums[greatest] - 1) * (nums[great] - 1);
        
        // Solution 2
        int great, greatest;
        great = greatest = 0;
        for(int i:nums)
        {
            if(i > greatest)
            {             
                great = greatest;  
                greatest = i; 
            }
            else
                great = max(i, great);
        }
        
        return (greatest -1) * (great - 1);
    }
};