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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return solution1(head, n);
        // return solution2(head, n);
    }
    
    //TC: O(N)
    ListNode* solution1(ListNode* &head, int n)
    {
        ListNode* i = head;
        ListNode* j = head;
        
        while(n--) //move the first pointer by N steps
            j = j->next;
        
        //if j is NULL, n should be equal to length of linked list, so head should be removed.
        if(!j)
            return head->next;

        //move both pointers till next of first pointer is nullptr. 
        //now the 2nd pointer should be at node before the node to be deleted.
        while(j && j->next)
        {
            i = i->next;
            j = j->next;
        }
        
        ListNode* temp = i->next;
        i->next = i->next->next; //delete the next node
        delete(temp);
        return head;
    }
    
    //TC: O(2N)
    ListNode* solution2(ListNode* &head, int &n)
    {
        ListNode* ptr = head;
        int count = 0;
        while(ptr)
        {
            count++;
            ptr = ptr->next;
        }
        count = count - n;
        ptr = head;
        ListNode* temp;
        
        //if count == 0, we have to remove last element from the right side of list, i.e. we have to remove the head of list
        if(!count)
        {
            temp = head->next;
            delete(head);
            return temp;
        }
        while(--count > 0)
        {
            ptr = ptr->next;
        }

        temp = ptr->next;
        ptr->next = ptr->next->next;
        delete(temp);
        return head;
    }
};