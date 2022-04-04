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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ex = NULL;
        ListNode* curr = l1;
        ListNode* prev = NULL;
        ListNode* next;
        int n = 0;
        
        //reverse first list
        while(curr)
        {
            n++;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        l1 = prev; //new head of list1
        
        //reverse second list
        curr = l2;
        prev = NULL;
        int m = 0;
        while(curr)
        {
            m++; 
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        l2 = prev; //new head of list2
        
        //treat bigger list as list1 and smaller list as l2 for easier operations
        //the bigger list can be used to update the answer in-place so we should know which list is bigger
        if(m > n)
        {
            ListNode* temp = l1;
            l1 = l2;
            l2 = temp;
        }
        
        curr = l1;
        int carry = 0;
        ListNode* ptr;
        while(l1 or l2) //add value of nodes of both list one by one and update list1 (l1) in-place
        {
            int l2val = (l2 ? l2->val : 0) + carry; //make sure l2 has a node at current index.
            carry = (l1->val + l2val) / 10;
            l1->val = (l1->val + l2val) % 10;

            ptr = l1;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }

        if(carry)
        {
            ListNode* head = new ListNode(carry);
            ptr->next = head;
        }
        
        //reverse the answer list
        prev = NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};