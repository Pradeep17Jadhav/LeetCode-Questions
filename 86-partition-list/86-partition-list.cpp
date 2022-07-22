class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* big = new ListNode(-1e3, head);
        ListNode* small = new ListNode(-1e3, head);
        ListNode* bigStart = NULL;
        ListNode* res = small;
        ListNode* temp;
        while(big->next) {
            if(!bigStart && big->next->val >= x) bigStart = big->next;
            if(big->next->val < x) {
                temp = big->next;
                big->next = big->next->next;
                small->next = temp;
                small = small->next;
            }
            else {
                big = big->next;
            }
        }
        if(small->val != -1e3)
            small->next = bigStart;
        return res->next;
    }
};