class Solution {
public:
    //there are two possible solutions for this question
    //1 - using hashmap - TC: O(n), SC: O(n)
    //2 - using sorting - TC: I(nlogn), SC: O(1)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        vector<int> res;
        while(i < nums1.size() and j < nums2.size())
        {
            if(nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        return res;
    }
};