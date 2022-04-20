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
class BSTIterator {
public:
    TreeNode* ptr;
    vector<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        ptr = root;
        while(ptr) {
            st.push_back(ptr);
            ptr = ptr->left;
        }
    }
    
    int next() {
        if(!ptr || (ptr->val == -1 && !ptr->right) || (ptr->val == -1 && ptr->right->val == -1)) {
            ptr = st.back();
            st.pop_back();
        }
        int val = 0;
        if(ptr->left && ptr->left->val != -1){
            val = ptr->left->val;
            ptr->left->val = -1;
        }
        else if(ptr->val != -1){
            val = ptr->val;
            ptr->val = -1;
        }
        else if(ptr->right && ptr->right->val != -1) {
            if(ptr->right) {
                ptr = ptr->right;
                while(ptr->left) {
                    st.push_back(ptr);
                    ptr = ptr->left;
                }
            }
            val = next();
        }
        return val;
    }
    
    bool hasNext() {
        if(!ptr && !st.empty())
            return true;
        
        if(ptr && ((ptr->val != -1) || (ptr->right && ptr->right->val != -1)))
            return true;
        
        if(!st.empty())
            return true;
        
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */