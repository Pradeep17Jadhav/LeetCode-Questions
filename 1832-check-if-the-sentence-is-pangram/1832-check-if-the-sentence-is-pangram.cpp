class Solution {
public:
    bool checkIfPangram(string s) {
        if(s.size() < 26) return false;
        return set<char>(s.begin(), s.end()).size() == 26;;
    }
};