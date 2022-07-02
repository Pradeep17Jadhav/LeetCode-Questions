class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // return recursive(root);
        // return iterative(root);
        // return MorrisTraversal(root);
        return iterative_easy(root);
        
    }
        
    //Solution 3 - Morris Traversal (IMP)
    //Note - Morris traversal for inorder and preorder has only 1 line of change
    //TC: almost (but not exactly) O(N)
    //SC: O(1) - only solution with constant SC
    vector<int> MorrisTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* ptr = root;
        
        while(ptr != NULL) {
            //Case 1 - ptr does not have left subtree
            if(ptr->left == NULL) {
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
                    ptr = ptr->right;
                }
                //in else, we start traversing left subtree
                //point the rightmost node's next of left subtree to current node i.e. ptr
                else {
                    newPtr->right = ptr;
                    res.push_back(ptr->val); //for preorder, first add to res and then move to left subtree
                    ptr = ptr->left;
                }
            }
        }
        return res;
    }

        
    //Solution 1 - Recursive
    //TC: O(N)
    //SC: O(N)
    vector<int> recursive(TreeNode* root) {
        vector<int> res;
        traverse_recursive(root, res);
        return res;
    }
    
    // Traversal function for Solution 1 (Recursive)
    void traverse_recursive(TreeNode* root, vector<int> &res) {
        if(!root)
            return;
        
        res.push_back(root->val);
        traverse_recursive(root->left, res);
        traverse_recursive(root->right, res);
    }
    
    // Solution 2 - Iterative using Stack
    //TC: O(N)
    //SC: O(N) stack size
    vector<int> iterative(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while(!st.empty() || root) {
            while(root) {
                res.push_back(root->val);
                st.push(root);
                root = root->left;
            }
            
            root = st.top();
            st.pop();
            root = root->right;
        }
        return res;
    }
    
    // Solution 4 - Iterative using Stack (EASY SOLUTION)
    //TC: O(N)
    //SC: O(N) stack size
    vector<int> iterative_easy(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            root = st.top();
            st.pop();
            res.push_back(root->val);
            
            if(root->right)
                st.push(root->right);
            
            if(root->left)
                st.push(root->left);
        }
        return res;
    }
};