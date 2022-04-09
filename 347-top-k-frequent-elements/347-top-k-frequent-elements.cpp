class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return topKFrequentSolution1(nums, k);
        // return topKFrequentSolution2(nums, k);
    }

    vector<int> topKFrequentSolution1(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //maxheap pq having pair of value-key
        vector<int> res;

        //add all element frequencies to hash
        for(int &i: nums)
            hash[i]++;

        //add all frequencies in maxheap priority q and always keep only keep k elements in queue whose freq is maximum
        for(auto kv: hash)
        {
            pq.push({kv.second, kv.first}); //keep frequency as first argument so the pq will be sorted as per max freq.
            if(pq.size() > k)
                pq.pop();
        }
        
        //for all remaining values in priority queue, add their keys to result array
        while(pq.size())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }

    vector<int> topKFrequentSolution2(vector<int>& nums, int k) {        
        unordered_map<int, int> hash;
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> res;
        
        //add all element frequencies to hash
        for(int &i: nums)
            hash[i]++;
        
        //add all frequencies in maxheap priority q and always keep only keep k elements in queue whose freq is maximum
        for(auto kv: hash)
        {
            pq.push(kv.second);
            if(pq.size() > k)
                pq.pop();
        }
        
        //for all hash values, check the values whose freq is greater than or equal to top value of priority queue
        //since its a maxheap, all the values in pq are the required frequencies so add their keys to result.
        for(auto kv: hash)
        {
            if(kv.second >= pq.top())
                res.push_back(kv.first);
        }
        
        return res;
    }
};