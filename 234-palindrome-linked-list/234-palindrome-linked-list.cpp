class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        //find the mid+1th node of the linked list
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //reverse the list from mid+1 to end
        ListNode* nextNode;
        ListNode* prev = NULL;
        while(slow)
        {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }
        
        while(prev && head->val == prev->val)
        {
            head = head->next;
            prev = prev->next;
        }
        
        return prev == NULL;
    }
};