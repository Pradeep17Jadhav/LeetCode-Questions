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
    //O(1*N) Solution
    //Break the linked list into two chains for odd and even. connect both chains at the end.
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* evenStart = head->next; //store head for even node
        ListNode* odd = head;
        ListNode* even = head->next;
        
        //traverse till end of the linked list
        while(even and even->next)
        {
            odd->next  = even->next; //connect odd to next odd node
            even->next =  odd->next->next; //connect even to next even node
            
            //move to next (new) odd and even node
            odd = odd->next;
            even = even->next;
        }
        
        //link end of odd linked list to start of even linked list
        odd->next = evenStart;
        return head;
    }
};