class Solution {
public:
    bool buddyStrings(string A, string B) {
        //diff length of string
        if(A.size() != B.size())
            return false;
        
        //same string having duplicates - eg - "abbc"
        if(A == B and unordered_set<char>(A.begin(), A.end()).size() < A.size()) // 
            return true;

        vector<int>diff;
        
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] != B[i])
                diff.push_back(i);
            
            if(diff.size() > 2)
                return false;
        }

        return diff.size() == 2 //should have diff chars at exactly 2 places
            && A[diff[0]] == B[diff[1]] // first mismatch of A should be equal to second mismatch of B
            && A[diff[1]] == B[diff[0]]; // second mismatch of A should be equal to first mismatch of B       
    }
};