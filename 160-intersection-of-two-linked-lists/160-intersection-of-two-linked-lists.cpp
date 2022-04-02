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
        return getIntersectionNodeSolution1(headA, headB);
        // return getIntersectionNodeSolution2(headA, headB);
    }
    
    ListNode *getIntersectionNodeSolution1(ListNode *A, ListNode *B) {
        int countA = 0;
        int countB = 0;
        ListNode* ptrA = A;
        ListNode* ptrB = B;
        
        while(ptrA)
            countA++, ptrA = ptrA->next;
        while(ptrB)
            countB++, ptrB = ptrB->next;
        
        if(countA > countB)
        {
            int diff = countA - countB;
            while(diff--)
                A = A->next;
        }
        if(countB > countA)
        {
            int diff = countB - countA;
            while(diff--)
                B = B->next;
        }
        while(A && B)
        {
            if(A == B)
                return A;
            A = A->next;
            B = B->next;
        }
        return NULL;
    }
    
    ListNode *getIntersectionNodeSolution2(ListNode *headA, ListNode *headB) {
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