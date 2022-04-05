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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* ptr = dummy;

        while(ptr && ptr->next) {
            if(ptr->next->val == val) {
                ListNode* temp = ptr->next;
                ptr->next = ptr->next->next;
                delete(temp);
            }
            else
                ptr = ptr->next;
        }
        
        return dummy->next;
    }
};