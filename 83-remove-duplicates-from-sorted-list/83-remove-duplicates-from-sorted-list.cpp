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
    
    // Refer for medium difficulty question
    // https://leetcode.com/submissions/detail/656696859/

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        ListNode* temp;
        while(head)
        {
            while(head->next && head->val == head->next->val)
            {
                temp = head->next;
                head->next = head->next->next;
                delete(temp);
            }

            head = head->next;
        }
        
        return ptr;
    }
};