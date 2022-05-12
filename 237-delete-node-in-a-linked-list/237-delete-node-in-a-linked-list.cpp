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
    void deleteNode(ListNode* node) {
        deleteNode_2(node);
    }
    void deleteNode_1(ListNode* node) {
        //since we cannot actually delete the current node without parent node,
        //we can replace the pointer of next node to current node, which is logically the same thing
        //in this method, the node is not actually deleted and can cause memory leak
        //example: 1-2-3-4-5, node is 3
        //replace node 3 by node 4

        *node = *node->next;
    }

    void deleteNode_2(ListNode* node) {
        //Copy the value of next node to current node,
        //point the current node to next->next
        //delete the next node as we copied it to current node

        ListNode* temp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete(temp);
    }
};