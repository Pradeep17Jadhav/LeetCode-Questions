class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // return recursive(root);
        // return iterative(root);
        return MorrisTraversal(root);
    }
        

    //Solution 3 - Morris Traversal (IMP)
    //TC: almost (but not exactly) O(N)
    //SC: O(1) - only solution with constant SC
    vector<int> MorrisTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* ptr = root;
        
        while(ptr != NULL) {
            //Case 1 - ptr does not have left subtree
            if(ptr->left == NULL) {
                //since left is null in inorder, current node is added to res and them right subtree is traversed
                res.push_back(ptr->val); 
                ptr = ptr->right;
            }
            //Case 2 - left subtree exists
            else {
                TreeNode* newPtr = ptr->left;
                
                //find the rightmost node of left subtree of ptr
                //it may happen that current node is being visited by the "rightmost node of left subtree"
                //to know if this is true, we traverse the left subtree again and check if rightmost node
                //points to the current pointer.
                //if YES (newPtr->right == ptr), then we remove the thread reference and move to right subtree
                //if NO (newPtr->right != NULL), it means we havent visited left subtree yet, so move to left subtree
                while(newPtr->right != NULL && newPtr->right != ptr) {
                    newPtr = newPtr->right;
                }
                
                //it means we are comming from left subtree left left subtree is already added to res.
                if(newPtr->right == ptr) {
                    newPtr->right = NULL; //remove reference thread
                    res.push_back(ptr->val);
                    ptr = ptr->right;
                }
                //in else, we start traversing left subtree
                //point the rightmost node's next of left subtree to current node i.e. ptr
                else {
                    newPtr->right = ptr;
                    ptr = ptr->left;
                }
            }
        }
        return res;
        
    }
    
    
        
    // Solution 2 - Iterative using Stack
    vector<int> iterative(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while(root || !st.empty()) {
            
            //keep pushing all left nodes in the stack
            while(root) {
                st.push(root);
                root = root->left;
            }
            
            //add value of stack top in res and remove it from stack
            root = st.top();
            st.pop();
            res.push_back(root->val);

            //change root to right subtree root to traverse right subtree
            root = root->right;
            
        }
        return res;
    }
    
    
    // Solution 1 - Recursive
    vector<int> recursive(TreeNode* root) {
        vector<int> res;
        traverse_recursive(root, res);
        return res;
        
    }
    
    //traversal function for solution 1
    void traverse_recursive(TreeNode* root, vector<int> &res) {
        if(!root)
            return;
        
        traverse_recursive(root->left, res);
        res.push_back(root->val);
        traverse_recursive(root->right, res);
    }
};