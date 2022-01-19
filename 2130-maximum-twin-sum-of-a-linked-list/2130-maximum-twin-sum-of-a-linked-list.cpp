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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        //reach middle of the linked list
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //reverse the 2nd half
        ListNode* prev = NULL;
        ListNode* nextNode;
        while(slow)
        {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }
        
        //add the twins and find max sum
        int res = 0;
        while(prev)
        {
            res = max(res, head->val + prev->val);
            head = head->next;
            prev = prev->next;
        }
        
        return res;
    }
};