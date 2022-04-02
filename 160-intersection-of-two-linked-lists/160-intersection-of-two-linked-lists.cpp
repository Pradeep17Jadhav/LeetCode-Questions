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
        // return getIntersectionNodeSolution3(headA, headB);
    }

    //TC: O(2m+2n) = O(m+n)
    //SC: O(1)
    ListNode *getIntersectionNodeSolution1(ListNode *A, ListNode *B) {
        ListNode* ptrA = A;
        ListNode* ptrB = B;
        
        while(ptrA != ptrB) //this will terminate when intersection is found or both lists become null 
        {
            //when either of list ends, start it again with head of other list
            //so on 2nd iteration of both lists, the will reach intersection at same time
            //if there is no intersection, both will reach NULL at same time
            //logic: Even if m>n or n>m, if we iterate m+n for both lists, len(m+n) == len(n+m)
            ptrA = ptrA ? ptrA->next : B;
            ptrB = ptrB ? ptrB->next : A;
        }
        return ptrA; //or return ptrB;
    }
    
    //TC: O(2m+2n) = O(m+n)
    //SC: O(1)
    ListNode *getIntersectionNodeSolution2(ListNode *A, ListNode *B) {
        int countA = 0;
        int countB = 0;
        ListNode* ptrA = A;
        ListNode* ptrB = B;
        
        //count the elements in each lists
        while(ptrA)
            countA++, ptrA = ptrA->next;
        while(ptrB)
            countB++, ptrB = ptrB->next;
        
        //if both list has unequal elements,  skip the 'diff' nodes from bigger list
        //since both the interected list should end at same point, the extra starting nodes of bigger list 
        //definately does not have the intersection so we just skip them
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
        
        //since both lists now have equal elements, we can find intersection by traversing them both simultaneously
        while(A && B)
        {
            if(A == B)
                return A;
            A = A->next;
            B = B->next;
        }
        return NULL;
    }
    
    //TC: O(m+n)
    //SC: O(m+n)
    ListNode *getIntersectionNodeSolution3(ListNode *A, ListNode *B) {
        unordered_set<ListNode*> hash;
        while(A || B)
        {
            if(A)
            {
                if(hash.count(A)) return A;
                hash.insert(A);
                A = A->next;
            }

            if(B)
            {
                if(hash.count(B)) return B;
                hash.insert(B);
                B = B->next;
            }
        }
        return NULL;
    }
};