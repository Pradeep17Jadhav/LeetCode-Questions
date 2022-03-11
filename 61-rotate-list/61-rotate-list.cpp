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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || head->next == nullptr || k == 0) 
            return head;

        int n = 1;
        ListNode* ptr = head;
        
        //traverse till last node
        while(ptr->next)
        {
            ptr = ptr->next;
            n++;
        }
        k = k % n;
        if(k == 0) //no need to rotate
            return head;
        
        //make list circular
        ptr->next = head;

        //traverse till the new tail node and them make its next null
        ptr = head;
        for(int i = 0; i < n-k-1; i++)
        {
            ptr = ptr->next;
        }
        head = ptr->next;
        ptr->next = nullptr;

        return head;
    }
};