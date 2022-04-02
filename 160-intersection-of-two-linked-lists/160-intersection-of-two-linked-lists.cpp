/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> hash;
        while(headA || headB)
        {
            if(headA)
            {
                if(hash.count(headA)) return headA;
                hash.insert(headA);
                headA = headA->next;
            }

            if(headB)
            {
                if(hash.count(headB)) return headB;
                hash.insert(headB);
                headB = headB->next;
            }
        }
        return NULL;
    }
};