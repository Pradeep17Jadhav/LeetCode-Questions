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
    //refer 116. Populating Next Right Pointers in Each Node I
    //here we we traverse through all the parent nodes for each depth
    //on each depth, we will traverse through each node and find the 'next' of all their child nodes
    Node* connect(Node* root) {
        Node *curr = root; //parent node on current depth
        Node *baseChild, *currChild, *nextChild; //child nodes on next depth
        while (curr)
        {
            // skipping childless nodes
            while (curr->next && !curr->left && !curr->right) 
                curr = curr->next;
            
            //set the new currChild, baseChild. either of them will surely be present as we skipped childless nodes
            currChild = baseChild = curr->left ? curr->left : curr->right;
            
            //iterate through all the curr depth nodes and form next all their childs
            while (currChild) 
            {
                // getting nextChild
                // check if right node exists, and it should not be already select as currChild
                if (curr->right && currChild != curr->right) 
                    nextChild = curr->right;
                else // use the child of a following parent
                {
                    // moving to the nextParent, if any
                    curr = curr->next;
                    
                    // moving childless parent nodes if any
                    while (curr && !curr->left && !curr->right)
                        curr = curr->next;
                    
                    // set nextChild to be the next left/right child, if any
                    nextChild = curr ? (curr->left ? curr->left : curr->right) : NULL;
                }
                
                currChild->next = nextChild; //link the current childnode to next child node
                currChild = nextChild; //move to next child node
            }

            // preparing for the next loop
            curr = baseChild;
        }
        return root;
    }
};
