class Solution {
public:
    //Solution 1 - 
    //Iterate over all nodes of list a and b.
    //Create a new head and Keep creating new nodes next to head for each sums of a and b
    //SC: O(max(a,b))
    
    //Solution 2 -
    //Iterate over all nodes of list a and b.
    //Find the sum of a and b and replace it in node of list a in-place
    //SC O(1)
    
    //NOTE - Can also be asked in reverse list. Then first we will reverse both the lists, then add the nodes and again reverse the answer.
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        ListNode* head = a; // use list "a" to store answer in-place
        ListNode* prev = a; // to keep track of prev node of answer list
        int carry = 0;
        int sum = 0;
        
        while(a || b) {
            //sum = carry + a + b
            sum = carry;
            if(a) sum += a->val;
            if(b) sum += b->val;
            
            carry = sum / 10; //update carry
            a->val = sum % 10; //use "a" list to update ans in-place

            //if list "b" has more nodes than list "a",
            //point the list "a" to remaining nodes of list "b"
            //so, we can use any list (a or b) to update answer in-place
            if(!a->next && b != NULL && b->next) {
                a->next = b->next;
                b->next = nullptr;
            }

            prev = a; //keep track of last node of list "a"
            
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