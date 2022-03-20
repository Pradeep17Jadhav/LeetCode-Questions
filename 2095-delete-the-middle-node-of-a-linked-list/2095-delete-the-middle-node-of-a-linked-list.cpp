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
    ListNode* deleteMiddle(ListNode* head) {
        return solution1(head);
        // return solution2(head);
    }
    
    ListNode* solution1(ListNode* head) {
        if(!head->next)
            return {};
        auto slow = head;
        auto fast = head->next->next;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        
        return head;
    }
    
    ListNode* solution2(ListNode* head) {
        if(!head->next)
            return {};
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next && fast->next->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* temp;
        if(fast->next)
        {
            temp = slow->next;
            slow->next = slow->next->next;
            delete(temp);
        }
        else
        {
            temp = prev->next;
            prev->next = slow->next;
            delete(slow);
        }

        return head;
    }
};