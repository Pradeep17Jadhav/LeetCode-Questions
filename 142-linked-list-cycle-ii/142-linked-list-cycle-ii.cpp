/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //Floyed's algorithm
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            //if slow fast intersects, cycle is found
            //continue to slow pointer and start from head at the same time. they will meet each other at the entry point
            if(slow == fast)
            {
                while(slow != head)
                {
                    slow = slow->next;
                    head = head->next;
                }
                return head;
            }
        }
        
        return NULL;
    }
};