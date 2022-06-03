class Solution {
public:
    int trap(vector<int>& height) {
        return trap_1(height);
        // return trap_2(height);
    }
    
    //Similar to trap_2 solution but more optimized
    //TC: O(N)
    //SC: O(1)
    int trap_1(vector<int>& height) {
        int res = 0;
        int maxHightLeft = 0, maxHeightRight = 0; //store max hight from both left and right side
        int leftIndex = 0, rightIndex = height.size() - 1; //pointers to current index from left and right
        
        //In loop we will move left pointer towards right and right pointer towards left
        //We will end out loop at the tallest bar
        while(leftIndex < rightIndex) 
        {
            //go from left to right when height of leftIndex pointer is less than rightIndex pointer. Else go from right to left
            if(height[leftIndex] <= height[rightIndex])
            {
                maxHightLeft = max(maxHightLeft, height[leftIndex]);
                res += maxHightLeft - height[leftIndex];
                leftIndex++;
            } 
            else 
            {
                maxHeightRight = max(maxHeightRight, height[rightIndex]);
                res += maxHeightRight - height[rightIndex];
                rightIndex--;
            }
        }
        return res;
    }
    
    //TC: O(3N) = O(N)
    //SC: O(3N) = O(N)
    //Referance - https://www.youtube.com/watch?v=UZG3-vZlFM4
    int trap_2(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        int res = 0;
        left[0] = height[0];
        right[n-1] = height[n-1];

        // Start from left and find the maximum height of all bars on the left side at current index
        for(int i = 1; i < n; i++)
            left[i] = max(left[i-1], height[i]);

        // Start from right side and find the maximum height of all bars on the right side at current index
        for(int i = n-2; i >= 0; i--)
            right[i] = max(height[i], right[i+1]);
        
        // Consider the min of both left and right heights at each index. 
        // Take the minimum of each (as water above the min will overflow no matter how tall the max is)
        // The water will trap at each bar excluding the height of bar so subtract it from min(left[i], right[i])
        for(int i = 0; i < n; i++)
            res += min(left[i], right[i]) - height[i];
        
        return res;
    }
};
