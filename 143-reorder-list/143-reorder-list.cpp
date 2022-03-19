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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* next;
        while(curr)
        {
            cout << curr->val << " ";
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;  
        }
        
        ListNode* front = head;
        ListNode* frontTemp;
        ListNode* back = prev;
        ListNode* backTemp;
        while(back->next)
        {
            frontTemp = front->next;
            backTemp = back->next;
            front->next = back;
            back->next = frontTemp;
            back = backTemp;
            front = frontTemp;
        }
    }
};