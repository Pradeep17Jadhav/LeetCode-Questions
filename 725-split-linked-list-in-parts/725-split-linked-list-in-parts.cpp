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
    //TC: O(N)
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* ptr = head;
        ListNode* temp;
        vector<ListNode*> res;
        int len = 0;
        
        //count the length of the linked list
        while(ptr)
            len++, ptr = ptr->next;
        
        int nodeCount;
        int extra = len % k;
        ptr = head;
        while(ptr)
        {
            res.push_back(ptr);
            nodeCount = len / k; //update required node count for each part, as it is being decremented each time
    
            //for the required number of nodes for each part, move ahead
            while(--nodeCount > 0)
                ptr = ptr->next;

            //add one extra node, if any, to each part. Do not add if length of given array is less than k
            if(extra && len > k) {
                ptr = ptr->next;
                extra--;
            }

            // move to next node
            // if length of given array < k, each single node will be added at start of while loop
            temp = ptr;
            ptr = ptr->next; 
            temp->next = NULL;
        }

        //if len < k, we will manually add the remaining empty nodes
        while(res.size() < k)
            res.push_back(NULL);

        return res;
    }
};