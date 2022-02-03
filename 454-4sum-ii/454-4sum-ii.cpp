class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        //bruteforce soln for this problem will have O(N^4) time complexity
        //so we divide it in 2*N^2 i.e. O(N^2) soln using map
        
        unordered_map<int, int>hash;
        int count = 0;
        
        //store sum of 2 nums in a map. it can be anything -1,0-1,2,.. etc
        for(int &i: nums1)
            for(int &j: nums2)
                hash[i+j]++;
        
        //now get sum of 2 nums from othr two arrays and negate it.
        //if hash contains "2" at some position, then to make it 0, there should be other two values with sum "-2"
        //so we just add and negate the sum and search in hash
        //if there are non zero values in hash, it means if we add non-negated number in it then it would result in 0.
        for(int&i: nums3)
            for(int &j: nums4)
                if(hash[-(i+j)]) count+=hash[-(i+j)];
        
        return count;
    }
};