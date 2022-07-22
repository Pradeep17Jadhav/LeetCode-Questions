class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        return partition_2(head, x);
    }
    
    ListNode* partition_2(ListNode* head, int x) {
        ListNode* small = new ListNode(0, head), *big =  new ListNode(0, head);
        ListNode* startSmall = small, *startBig = big;

        while(head) {
            if(head->val < x) {
                small->next = head;
                small = small->next;
            }
            else {
                big->next = head;
                big = big->next;
            }
            head = head->next;
        }
        big->next = NULL;
        small->next = startBig->next;
        return startSmall->next;
    }
};