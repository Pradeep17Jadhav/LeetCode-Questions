class Solution {
public:
    // IMPORTANT - GAP Algorithm
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        Start_from_end(nums1, m, nums2, n);
        // GAP_Algo(nums1, m, nums2, n); //important
        // Naive_Merge(nums1, m, nums2, n);
    }
    
    //TC : O(m+n) = O(N)
    //SC: O(1)
    //It is guaranteed that all elements will accomodate in nums1
    //Start iterating from end of both the arrays and compare them.
    //Use a ptr at end of nums1 which will be used to update the whole array
    //Just compare the ith and jth value and put the greatest value at the end using ptr
    void Start_from_end(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr = nums1.size() - 1;
        int i = m - 1;
        int j = n - 1;
        
        while(i >= 0 && j >= 0)
        {
            if(nums1[i] > nums2[j])
                nums1[ptr--] = nums1[i--];
            else
                nums1[ptr--] = nums2[j--];
        }

        //if j becomes 0 first, the remaining elements in nums1 before i are already sorted so we got the answer
        //if i becomes 0 first, then there must be few elements left in nums2 which are smaller than ith element. so add them to the nums1
        while(j >= 0)
            nums1[ptr--] = nums2[j--];
    }

    
    // TC : O(NlogN)
    // SC : O(1)
    void GAP_Algo(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int maxN = nums1.size();
        
        //starting Gap should be maxN/2 for even length, (maxN+1)/2 for odd
        //let maxN=6, gap=(6+0)/2=3, let maxN=7, gap=(7+1)/2=4
        //gap can be odd or even
        int gap = (maxN + (maxN % 2)) / 2; 
        int ptr1 = 0;
        int ptr2 = gap;
        
        //fill elements of nums2 in empty extra space in nums1
        for(int i = 0; i < n; i++)
            nums1[m + i] = nums2[i];
        
        while(gap >= 1)
        {
            while(ptr2 < maxN)
            {
                //compares values of ptr1 and ptr2 and swap if required such that lower value should be placed on ptr1
                if(nums1[ptr1] > nums1[ptr2])
                    swap(nums1[ptr1], nums1[ptr2]);
                ptr1++;
                ptr2++;
            }

            gap = gap == 1 ? 0: (gap + gap%2) / 2; //handle both odd and even gaps
            ptr1 = 0;
            ptr2 = gap;
        }
    }


    //Naive Solution - Not for interviews
    // TC : O(NlogN)
    // SC : O(1)
    void Naive_Merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m, j = 0; i < nums1.size(), j < n; i++, j++)
        {
            nums1[i] = nums2[j];
        }
        sort(nums1.begin(), nums1.end());
    }
};