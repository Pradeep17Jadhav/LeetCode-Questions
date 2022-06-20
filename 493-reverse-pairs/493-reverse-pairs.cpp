class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
    
    int mergeSort(vector<int> &arr, int start, int end) {
        if(start >= end)
            return 0;

        int mid = (start + end) / 2;
        int reversePairCount = mergeSort(arr, start, mid);
        reversePairCount += mergeSort(arr, mid+1, end);
        reversePairCount += merge(arr, start, mid, end);

        return reversePairCount;
    }
    
    int merge(vector<int> &arr, int start, int mid, int end) {
        int reversePairCount = 0;
        int i, j;
        i = start;
        j = mid+1;
        
        //count the reverse pairs
        while(i <= mid) {
            while(j <= end && arr[i] > 2LL * arr[j]) //note that we do not reinitialize j to mid+1 to keep TC: O(N)
                j++;

            reversePairCount += j - (mid+1);
            i++;
        }

        i = start;
        j = mid+1;
        vector<int> arrNew;
        
        //traverse both parts and keep adding smaller element in new array
        while(i <= mid && j <= end) {
            if(arr[i] <= arr[j]) {
                arrNew.push_back(arr[i++]);
            }
            else {
                arrNew.push_back(arr[j++]);
            }
        }

        //once one of the part is exhausted, we will have to add remaining elements of other part to the array
        while(i <= mid) {
            arrNew.push_back(arr[i++]);
        }

        while(j <= end) {
            arrNew.push_back(arr[j++]);
        }

        //copy back the sorted array to original array
        for(i = start; i <= end; i++)
            arr[i] = arrNew[i - start];
        
        return reversePairCount;
    }
};