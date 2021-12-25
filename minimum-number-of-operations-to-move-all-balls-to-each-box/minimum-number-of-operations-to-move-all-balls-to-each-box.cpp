class Solution {
public:
    vector<int> minOperations(string boxes) {
        // Input: boxes = "110"
        // Output: [1,1,3]
        int n = boxes.size();
        int behind = 0;
        int ahead = 0;
        
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++)
        {
            if(boxes[i] == '1')
            {
                ahead++;
                ans[0] += i;
            }
        }
        for(int i = 1; i < n; i++)
        {
            if(boxes[i-1] == '1')
            {
                behind++;
                ahead--;
            }
            
            ans[i] = ans[i-1] - ahead + behind;
        }
        return ans;
    }
};