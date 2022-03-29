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
        return solution1(head, nums);
        // return solution2(head, nums);

    }
    
    int solution1(ListNode* head, vector<int>& nums) {
        //set is used to store values of nums as it has same time complexity for find()
        unordered_set<int> list(nums.begin(), nums.end());
        int res = 0;
        while(head)
        {
            //check if current value is in list
            //if yes, check if it is the last node or next node is in list or not
            //if next node is not available or not in list, it means the chain is completed, so res++
            if(list.count(head->val) && (!head->next || !list.count(head->next->val)))
                res++;
            head = head->next;
        }
        return res;
    }
    
    int solution2(ListNode* head, vector<int>& nums) {
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