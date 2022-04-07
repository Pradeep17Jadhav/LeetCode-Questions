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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        return reverseBetweenSolution1(head, left, right);
        // return reverseBetweenSolution2(head, left, right);
    }
        
    ListNode* reverseBetweenSolution1(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        ListNode* curr = NULL;
        ListNode* temp = NULL;
        int diff = right-left;

        //find the node before the 'left' node which has to be reversed
        while(--left)
            pre = pre->next;
        curr = pre->next; //left node from which reverse is started

        //important.. take a dry run to understand
        //keep pre and curr constant, just change the next pointer of each node to prev node
        //keep updating next of pre and next of curr
        while(diff--) {
           temp = pre->next;
           pre->next = curr->next;
           curr->next = curr->next->next;
           pre->next->next = temp;
       }
       return dummy->next;
    }
    
    ListNode* reverseBetweenSolution2(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* l = dummy;
        ListNode* r = dummy->next;
        ListNode* revEnd = NULL;
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        right = right - left + 1;
        
        while(l) {
            if(left-1 > 0) {
                l = l->next;
                r = r->next;
                left--;
            }
            else if(!revEnd) {
                revEnd = r;
            }
            else if(right) {
                right--;
                temp = r->next;
                r->next = prev;
                prev = r;
                r = temp;
            }
            else {
                l->next = prev;
                revEnd->next = r;
                break;
            }
        }
        return dummy->next;
    }
};