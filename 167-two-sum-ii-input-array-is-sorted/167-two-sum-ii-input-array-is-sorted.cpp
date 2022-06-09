class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        int diff;
        
        //since array is sorted and there is an unique solution
        //we can narrow down the two pointers to the solution
        while(left < right) {
            diff = target - (numbers[left] + numbers[right]);
            if(diff == 0)
                return {left+1, right+1};
            else if(diff < 0)
                right--;
            else 
                left++;
        }
        
        return {};
    }
};