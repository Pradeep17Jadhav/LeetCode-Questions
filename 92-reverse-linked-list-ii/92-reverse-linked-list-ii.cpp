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