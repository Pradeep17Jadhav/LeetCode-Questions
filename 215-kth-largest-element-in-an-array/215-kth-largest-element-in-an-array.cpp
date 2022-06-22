class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // return findKthLargest_1(nums, k);
        // return findKthLargest_2(nums, k);
        return findKthLargest_3(nums, k);
    }
    
    //Naive solution, sort and return (n-k)th element
    //TC: O(nlogn)
    int findKthLargest_1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
    
    //max heap
    int findKthLargest_2(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        while(--k)
            pq.pop();
        
        return pq.top();
    }
    
    //min heap
    int findKthLargest_3(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>> pq;

        for(int &i: nums) {
            pq.push(i);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        return pq.top();
    }
};