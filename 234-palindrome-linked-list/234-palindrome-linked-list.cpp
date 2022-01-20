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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* nextNode;
        ListNode* prev = NULL;
        while(slow)
        {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }
        
        while(prev and head->val == prev->val)
        {
            head = head->next;
            prev = prev->next;
        }
        
        return prev == NULL;
    }
};