class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // return findKthLargest_1(nums, k);
        return findKthLargest_2(nums, k);
    }
    
    int findKthLargest_1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
    
    int findKthLargest_2(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        while(--k)
            pq.pop();
        
        return pq.top();
    }
};