/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;

        Node* curr = root;
        Node* next = root->left;
        
        //for all depths, start with left-most node
        while(curr->left)
        {
            //store the left-most node of next depth
            next = curr->left;
            
            //for all nodes in current depth, find the 'next' of all the child nodes
            while(curr)
            {
                //as its a perfect binary tree, 'next' of curr->left should be curr->right
                curr->left->next = curr->right;
                
                //if curr has next set, it means its parent node has right subtree
                //since the curr->next points to root of right subtree (parent->right), we will
                //set its left i.e. parent->right->left (or curr->next->left) as curr->right->next
                if(curr->next != NULL)
                    curr->right->next = curr->next->left; 
                
                //move to next node at the same depth
                curr = curr->next;
            }
            
            //when all the nodes in current depth are traversed, move to the left-most node of next depth
            curr = next;
        }
        return root;
    }
};