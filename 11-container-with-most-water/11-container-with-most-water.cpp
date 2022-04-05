class Solution {
public:
    int maxArea(vector<int>& height) {
        return maxAreaSolution1(height);
        // return maxAreaSolution2(height);

    }
    
    //TC: O(N) - two pointers. Similar to solution 1, but concise;
    int maxAreaSolution1(vector<int>& height) {
        int i = 0; //left ptr
        int j = height.size() - 1; //right ptr
        int res = 0;
        int minHeight; //height of shorter line between two

        
        //we will start from lines at extreme ends to consider the whole container.
        //then we check the inner lines having height higher than current line.
        //the inner container can have higher area IFF its height is considerably more as the width is always less.
        //so we check for all the inner lines which have higher height than current line
        while(i < j)
        {
            minHeight = min(height[i], height[j]);
            res = max(res, minHeight * (j-i));
            
            while(height[i] <= minHeight && i < j)
                i++;
            while(height[j] <= minHeight && i < j)
                j--;
        }
        return res;
    }

    //TC: O(N) - four pointers are used. similar to solution 1.
    int maxAreaSolution2(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int i = left;
        int j = right;
        int res = min(height[i], height[j]) * (j-i);
        
        while(i < j)
        {
            if(height[left] > height[right]) {
                while(height[right] >= height[j])
                    j--;
                right = j;
            }
            else if(height[left] < height[right]) {
                while(height[left] >= height[i])
                    i++;
                left = i;
            }
            else
            {
                left++;
                i++;
            }
            res = max(res, min(height[left], height[right]) * (j-i));
        }
        return res;
    }
};