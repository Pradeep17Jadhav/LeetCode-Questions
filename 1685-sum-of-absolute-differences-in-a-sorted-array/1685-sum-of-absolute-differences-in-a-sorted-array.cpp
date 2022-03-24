class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sumAfter = 0;  //sum of all elements
        for(int &i: nums) //first find the total sum of all the elements in array
            sumAfter += i;

        //Formula:: val = (elementsBefore * nums[i] - sumBefore) + 0 + (sumAfter - elementsAfter * nums[i]);
        //---------------------------------------------------------------------
        //absolute diff with current element is always 0 so it can be ignored
        //Suppose there are 4 elements before current element. Then we will have to compare all of them with
        //current element, so we compare 'elementsBefore' * nums[i], i.e.
        //let [1 4 6 8 10], and current is 2nd index i.e. 6.
        //then summation of absolute differences on left of 6 = (6-1)+(6-4) = 6*2+(-1-4) = 7
        //this can be written as = (6+6+...+6)-(1+4+...+x)
        // = (elementsBefore * nums[i]) - (sum of elements before current element)
        // = (elementsBefore * nums[i] - sumBefore)
        
        //Similarly we can use similar approach to find the summation of absolute differences on right side
        //let [1 4 6 8 10], and current is 2nd index i.e. 6.
        //summation of absolute differences on right of 6 = (8-6)+(10-6) = (8+10)-6*2 = 6
        // = (8+10+...+x) - (6+6+...+6)
        // = (sum of elements after current element) - (elementsAfter * nums[i])
        // = (sumAfter - elementsAfter * nums[i])

        int sumBefore = 0; //sum of all elements before the current element
		int elementsBefore, elementsAfter, val;
        vector<int>res;
        for(int i = 0; i < nums.size(); i++) {
            sumAfter -= nums[i];
            elementsBefore = i;
            elementsAfter = nums.size() - i - 1;
            val = (sumAfter - elementsAfter * nums[i]) + (elementsBefore * nums[i] - sumBefore);
            res.push_back(val);
            sumBefore += nums[i];
        }
        return res;
    }
};