class Solution {
public:
    bool areOccurrencesEqual(string s) {
        // return usingMap(s);
        return usingVector(s);
    }

    //vector uses constant time for accessing element
    bool usingVector(string &s)
    {
        vector<int>hash(26);
        for(char &c:s) 
            hash[c - 'a']++;

        for(int &i: hash)
        {
            if(i and i != hash[s[0] - 'a']) 
                return false;
        }
        return true;
    }

    //map uses logarithmic time for accessing element
    bool usingMap(string &s)
    {
        unordered_map<char, int>hash;
        for(char &c:s) hash[c]++;
        for(auto &[k, v]:hash)
            if(v != hash[s[0]]) return false;
        return true;
    }
};