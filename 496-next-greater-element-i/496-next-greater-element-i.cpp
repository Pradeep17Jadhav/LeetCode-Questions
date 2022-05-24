class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> hash;
        for(int i = 0; i< B.size(); i++)
            hash[B[i]] = i;
        
        vector<int> res;
        for(int i = 0; i < A.size(); i++) {
            int origIndex = hash[A[i]];
            int k = origIndex;
            int val = -1;
            while(++k < B.size()) {
                if(B[k] > B[origIndex]) {
                    val = B[k];
                    break;
                }
            }
            res.push_back(val);
        }
        
        return res;
    }
};