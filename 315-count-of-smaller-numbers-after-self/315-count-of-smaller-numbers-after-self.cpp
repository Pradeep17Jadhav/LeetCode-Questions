class Solution {
public:
    void merge(vector<int> &count, vector<pair<int, int> > &v, int left, int mid, int right) {
        vector<pair<int, int> > tmp(right-left+1);
        int i = left;
        int j = mid+1;
        int k = 0;

        while (i <= mid && j <= right) {
            if (v[i].first <= v[j].first)
                tmp[k++] = v[j++];
            else {
                count[v[i].second] += right - j + 1;
                tmp[k++] = v[i++];
            }
        }
        while (i <= mid) 
            tmp[k++] = v[i++];
        while (j <= right)
            tmp[k++] = v[j++];
        for (int i = left; i <= right; i++)
            v[i] = tmp[i-left];
    }        

    void mergeSort(vector<int> &count, vector<pair<int, int> > &v, int left, int right) {
        if (right <= left) return;

        int mid = left + (right-left)/2;
        mergeSort(count, v, left, mid);
        mergeSort(count, v, mid+1, right);
        merge(count, v, left, mid, right);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();

        vector<pair<int, int> > v(N);
        for (int i = 0; i < N; i++)   
            v[i] = make_pair(nums[i], i);

        vector<int> count(N, 0);
        mergeSort(count, v, 0, N-1);
        return count;
    }
    
    //Gives TLE - 55 / 65 test cases passed.
//     vector<int> countSmallerTLE(vector<int>& nums) {
//         int ptr = nums.size()-1;
//         map<int, int>mp;
//         vector<int> counts(nums.size(), 0);
        
//         while(ptr >= 0) {
//             int count = 0;
//             for(auto it: mp) {
//                 if(it.first >= nums[ptr])
//                     break;
//                 count += it.second;
//             }
//             counts[ptr] = count;
//             mp[nums[ptr]]++;
//             ptr--;
//         }
        
//         return counts;
//     }
};