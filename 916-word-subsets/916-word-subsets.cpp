class Solution {
public:
    vector<string> wordSubsets(vector<string>& word1, vector<string>& word2) {
        vector<int> count(26), temp(26);
        int i;
        for (string b : word2) {
            temp = counter(b);
            for (i = 0; i < 26; i++)
                count[i] = max(count[i], temp[i]);
        }
        vector<string> res;
        for (string a : word1) {
            temp = counter(a);
            for (i = 0; i < 26; i++)
                if (temp[i] < count[i])
                    break;
            if (i == 26) res.push_back(a);
        }
        return res;
    }

    vector<int> counter(string& word) {
        vector<int> count(26);
        for (char c : word) count[c - 'a']++;
        return count;
    }
};