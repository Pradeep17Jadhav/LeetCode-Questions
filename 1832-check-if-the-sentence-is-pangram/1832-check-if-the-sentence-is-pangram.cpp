class Solution {
public:
    bool checkIfPangram(string s) {
        return set<char>(s.begin(), s.end()).size() == 26;
    }
    
    //easy to understand
    bool checkIfPangramEasy(string s) {
        set<int> st;
        for (auto &c: s)
            st.insert(c);
        return s.size() == 26;
    }
};