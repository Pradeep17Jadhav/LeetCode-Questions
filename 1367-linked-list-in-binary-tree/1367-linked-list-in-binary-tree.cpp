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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) 
            return false;
        
        //for each treenode, first check if a linked list starts from this. return true if linked list is found
        //if not found, move to left and rightsubtree and repeat the process
        return CheckSubpath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
    
    bool CheckSubpath(ListNode* head, TreeNode* root)
    {
        if(!head) return true; //if !head, it means we have matched all nodes of the linked list
        if(!root) return false; //if head != NULL and still root is null, it means linked list remains incomplete
        
        //first check if values of tree node and list node are equal.
        //if equal, then only check left and right subtree of the treenode for next head and root
        //if unequal, the subpath doesnt has given linked list elements in it so false will be returned
        return head->val == root->val && 
            (CheckSubpath(head->next, root->left) || CheckSubpath(head->next, root->right));
    }
};