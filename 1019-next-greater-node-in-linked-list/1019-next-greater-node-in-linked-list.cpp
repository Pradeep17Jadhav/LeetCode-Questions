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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int>vals;
        vector<int>res;

        //push all linked list elements in an array
        while(head)
        {
            res.push_back(head->val);
            head = head->next;
        }
        
        //start traversing array from end
        for(int i = res.size() - 1; i >= 0; i--)
        {
            int curr = res[i];
            
            //remove all stack elements which are less than and equal to current element
            //this elements are not required anymore
            while(!vals.empty() and vals.top() <= curr)
            {
                vals.pop();
            }
            
            //if stack is empty enter 0, else top of stack will be the next greater number
            res[i] = vals.empty() ? 0 : vals.top();
            
            //add current element to stack as it can be answer for next element
            vals.push(curr);
        }

        return res;
    }
};