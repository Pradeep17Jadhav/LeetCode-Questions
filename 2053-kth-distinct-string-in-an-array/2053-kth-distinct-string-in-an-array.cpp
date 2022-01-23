class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> dist;  
        for(string &s: arr)
            dist[s]++;

        for(string &s: arr)
        {
            if(dist[s] == 1 and !--k)
                return s;
        }
        return "";
    }
};