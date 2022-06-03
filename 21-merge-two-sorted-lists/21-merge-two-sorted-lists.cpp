class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(!a) return b;
        if(!b) return a;
        ListNode* head; //ptr to store start node

        //initialize list with lowest value
        if(a->val <= b->val){
            head = a;
            a = a->next;
        }
        else {
            head = b;
            b = b->next;
        }
        
        //ptr to traverse
        ListNode* ptr = head;

        while(a && b) {
            if(a->val <= b->val) {
                ptr->next = a;
                a = a->next;
            }
            else {
                ptr->next = b;
                b = b->next;
            }
            ptr = ptr->next;
        }
        
        //join the remaining part of list
        ptr->next = a ? a : b;
        return head;
    }
};