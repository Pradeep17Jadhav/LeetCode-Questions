class Solution {
public:
    int minDeletions(string s) {
        vector<int> hash(26, 0);
        priority_queue<int> pq;
        int deletions = 0;

        for(char &c: s)
            hash[c-'a']++;
        
        for(int i: hash) {
            if(i != 0)
                pq.push(i);            
        }

        int curr;
        int last = pq.top();
        pq.pop();
        
        while(!pq.empty()) {
            int deleteCount = 0;
            curr = pq.top();
            pq.pop();
            if(curr >= last) {
                if(last == 0)
                    deleteCount = curr;
                else
                    deleteCount = curr - (last-1);
                deletions += deleteCount;
            }
            
            last = curr - deleteCount;
        }
        return deletions;
    }
};