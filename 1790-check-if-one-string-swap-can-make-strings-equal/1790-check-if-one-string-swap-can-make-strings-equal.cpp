class Solution {
public:
    bool areAlmostEqual(string A, string B) {
        if(A == B)
            return true;

        vector<int>diff;
        
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] != B[i])
                diff.push_back(i);
            
            if(diff.size() > 2)
                return false;
        }

        return diff.size() == 2 &&
            A[diff[0]] == B[diff[1]] &&
            A[diff[1]] == B[diff[0]];
    }
};