class Solution {
public:
    // IMPORTANT - GAP Algorithm
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        GAP_Algo(nums1, m, nums2, n);
        // Naive_Merge(nums1, m, nums2, n);
    }
    
    // TC : O(NlogN)
    // SC : O(1)
    void GAP_Algo(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int maxN = nums1.size();
        int gap = (maxN + (maxN % 2)) / 2;
        int ptr1 = 0;
        int ptr2 = gap;
        
        for(int i = 0; i < n; i++)
            nums1[m + i] = nums2[i];
        
        while(gap >= 1)
        {
            while(ptr2 < maxN)
            {
                if(nums1[ptr1] > nums1[ptr2])
                    swap(nums1[ptr1], nums1[ptr2]);
                ptr1++;
                ptr2++;
            }

            gap = gap == 1 ? 0: (gap + gap%2) / 2;
            ptr1 = 0;
            ptr2 = gap;
        }
    }
    
    //Naive Solution - Not for interviews
    void Naive_Merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m, j = 0; i < nums1.size(), j < n; i++, j++)
        {
            nums1[i] = nums2[j];
        }
        sort(nums1.begin(), nums1.end());
    }
};