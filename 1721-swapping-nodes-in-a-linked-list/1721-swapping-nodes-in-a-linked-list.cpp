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
    
    //O(1*N) solution
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* front = head;
        int n = k;
        
        //travel till Kth node
        while(--n)
        {
            front = front->next;
        }
        
        //store pointer to the Kth node
        ListNode* ptr = front;
        
        //start traversing back and front pointer
        //back pointer starts from head
        //when front reaches end, back will be at (N - Kth) position
        ListNode* back = head;  
        while(front->next)
        {
            front = front->next;
            back = back->next;
        }
        
        //swap stored pointer value and back pointer value
        swap(ptr->val, back->val);

        return head;
    }
};