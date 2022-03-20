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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        int count = 0;
        while(ptr)
        {
            count++;
            ptr = ptr->next;
        }
        count = count - n;
        ptr = head;
        ListNode* temp;
        if(!count)
        {
            temp = head->next;
            delete(head);
            return temp;
        }
        while(--count > 0)
        {
            ptr = ptr->next;
        }

        temp = ptr->next;
        ptr->next = ptr->next->next;
        delete(temp);
        return head;
    }
};