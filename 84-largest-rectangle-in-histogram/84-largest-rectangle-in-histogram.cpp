class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int n = height.size();
        stack<int> stack;
        int i = 0, maxArea = 0;
        while (i < n) 
        {
            if(stack.empty() or height[i] >= height[stack.top()])
            {
                stack.push(i++);
            }
            else
            {
                int h = stack.top();
                stack.pop();
                maxArea = max(maxArea, height[h] * (stack.empty() ? i : i - stack.top() - 1));
            }
        }
        return maxArea;
    }
};