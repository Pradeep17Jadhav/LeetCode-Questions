class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int i = left;
        int j = right;
        int maxx = min(height[i], height[j]) * (j-i);
        
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
            maxx = max(maxx, min(height[left], height[right]) * (j-i));
        }
        return maxx;
    }
};