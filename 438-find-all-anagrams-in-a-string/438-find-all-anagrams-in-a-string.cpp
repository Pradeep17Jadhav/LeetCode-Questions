class Solution {
public:
    //sliding window solution
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        if(s.size() < p.size()) return res;
        vector<int>shash(26);
        vector<int>phash(26);
        for(int i = 0; i < p.size(); i++)
        {
            shash[s[i] - 'a']++;
            phash[p[i] - 'a']++;
        }
        
        if(shash == phash) //O(26)
            res.push_back(0);

        for(int i = p.size(); i < s.size(); i++)
        {
            shash[s[i] - 'a']++; // slide window ahead, i.e. include next number
            shash[s[i - p.size()] - 'a']--; // discard first number as window has moved forward
            
            if(shash == phash) // O(26)
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
};