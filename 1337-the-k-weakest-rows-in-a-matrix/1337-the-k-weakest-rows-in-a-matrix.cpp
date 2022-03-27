class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int i = 0;
        int n = mat[0].size(); //size of all arrays is same

        for(auto &v: mat)
            mat[i].push_back(i++); //append the index of all elements to the same elements

        sort(mat.begin(), mat.end()); //in stl sort, both the given conditions are automatically satisfied
        
        vector<int>res;
        for(i = 0; i < k; i++)
            res.push_back(mat[i][n]); //get the original index from sorted array
        return res;
    }
};