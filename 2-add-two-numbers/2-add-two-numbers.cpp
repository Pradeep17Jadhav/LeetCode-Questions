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
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        ListNode* head = a; // use list "a" to store answer in-place
        ListNode* prev = a; // to keep track of prev node of answer list
        int carry = 0;
        int sum = 0;
        
        while(a || b)
        {
            //sum = carry + a + b
            sum = carry;
            if(a) sum += a->val;
            if(b) sum += b->val;
            
            carry = sum / 10; //update carry
            a->val = sum % 10; //use "a" list to update ans in-place

            //if list "b" has more nodes than list "a",
            //point the list "a" to remaining nodes of list "b"
            //so, we can use any list (a or b) to update answer in-place
            if(b && b->next && !a->next)
            {
                a->next = b->next;
                b->next = nullptr;
            }

            //keep track of last node of list "a"
            prev = a;
            
            //move to next nodes
            if(a) a = a->next;
            if(b) b = b->next;

        }
        
        //add new node for carry at the end
        if(carry)
            prev->next = new ListNode(carry, nullptr);

        return head;
    }
};