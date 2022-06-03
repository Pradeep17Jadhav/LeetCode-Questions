class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(!a) return b;
        if(!b) return a;
        ListNode* head; //ptr to store start node
        ListNode* ptr; //ptr to traverse

        //initialize list with lowest value
        if(a->val <= b->val){
            ptr = head = a;
            a = a->next;
        }
        else {
            ptr = head = b;
            b = b->next;
        }

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