class Solution {
public:
    //Steps -
    //It doesnt has left node, do nothing
    //If it has left node -
    //      - Save right node in temp
    //      - Copy left node to right
    //      - Go to rightmost node of right
    //      - Attach rightmost node to temp (right of current root)
    //      - Make right node of root as new root, and repeat
    void flatten(TreeNode* root) {
        if(!root) return;

        TreeNode* temp = root->right;    
        root->right = root->left;
        root->left = NULL;
        TreeNode* ptr = root;

        while(ptr->right)
            ptr = ptr->right;

        ptr->right = temp;
        root = root->right;
        flatten(root);
    }
};