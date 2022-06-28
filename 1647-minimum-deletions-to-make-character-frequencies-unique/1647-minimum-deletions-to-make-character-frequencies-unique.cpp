class Solution {
public:
    int minDeletions(string s) {
        vector<int> hash(26, 0);
        priority_queue<int> pq;
        int deletions = 0;

        //count frequency of all chars in the string
        for(char &c: s)
            hash[c-'a']++;
        
        //sort the frequencies using priority queue
        for(int i: hash) {
            if(i != 0)
                pq.push(i);            
        }

        int curr;
        int last = pq.top();
        pq.pop();
        
        //for each char in PQ, make the next char, of equal of hight frequency, to have less frequency than current char
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