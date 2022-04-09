class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> res;
        for(int &i: nums)
            hash[i]++;
        
        for(auto kv: hash)
        {
            pq.push(kv.second);
            if(pq.size() > k)
                pq.pop();
        }
        
        for(auto kv: hash)
        {
            if(kv.second >= pq.top())
                res.push_back(kv.first);
        }
        
        return res;
    }
};