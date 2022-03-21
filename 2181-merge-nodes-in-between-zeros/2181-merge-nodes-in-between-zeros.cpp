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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ptr = head->next;
        ListNode* resPtr = head; //pointer to latest result node (updating same list in-place)
        int sum = 0;
        
        //iterate the list from 1 index
        while(ptr)
        {
            if(ptr->val == 0) //add sum value to same list in-place
            {
                resPtr = resPtr->next;
                resPtr->val = sum;
                sum = 0;
            }
            else
                sum += ptr->val; //keep incrementing sut till we find 0 in value
            
            ptr = ptr->next;
        }

        //free unused notes
        ListNode* temp = resPtr->next;
        ListNode* nxt;
        while(temp)
        {
            nxt = temp->next;
            delete(temp);
            temp = nxt;
        }

        resPtr->next = NULL;
        return head->next;
    }
};