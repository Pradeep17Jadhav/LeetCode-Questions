class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int len = arr.size();
        int req = len/2;
        unordered_map<int, int> mp;
        for(int i: arr)
            mp[i]++;
        
        priority_queue<int> pq;
        for(auto &[f, s]: mp)
            pq.push(s);
        
        int res = 0;
        while(req > 0) {
            req -= pq.top();
            pq.pop();
            res++;
        }
        
        return res;
    }
};