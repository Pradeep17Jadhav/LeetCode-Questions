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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) 
            return head;
            
        ListNode* temp = head->next; //a temporary ptr to store head->next
        head->next = swapPairs(head->next->next); //changing the links
        temp->next = head; //put temp->next to head
        return temp;
    }
};