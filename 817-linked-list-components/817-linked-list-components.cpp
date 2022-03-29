/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int, bool> hash;
        //maintain hash for each number we want to find
        for(int &i: nums)
            hash[i] = true;

        ListNode* curr = head;
        int bPrevExists = false;
        int res = 0;
        while(curr || bPrevExists)
        {
            if(!curr) //handle last element
            {
                res++;
                break;
            }
            
            //ignore till continuous chain of element is formed,
            //count when chain breaks
            if(bPrevExists && !hash[curr->val]) 
                res++;

            bPrevExists = hash[curr->val];
            curr = curr->next;    
        }
        return res;
    }
};