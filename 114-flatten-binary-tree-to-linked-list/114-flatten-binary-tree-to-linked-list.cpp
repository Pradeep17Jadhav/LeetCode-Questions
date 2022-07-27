class Solution {
public:
    //Steps -
    //It doesnt has left node, do nothing
    //If it has left node (Follow inline comments to understand each step) -
    //      - Save right node in temp
    //      - Copy left node to right
    //      - Go to rightmost node of right
    //      - Attach rightmost node to temp (right of current root)
    //      - Make right node of root as new root, and repeat

    void flatten(TreeNode* root) {
        // recursive(root);
        iterative(root);
    }
    
    void iterative(TreeNode* root) {
        if(!root) return;

        while(root) {
            TreeNode* temp = root->right; //Save right node in temp
            root->right = root->left; //Copy left node to right
            root->left = NULL;
            TreeNode* ptr = root; //preserve root for traversal

            //Go to rightmost node of right
            while(ptr->right)
                ptr = ptr->right;

            ptr->right = temp; //Attach rightmost node to temp (right of current root)
            root = root->right; //Make right node of root as new root, and repeat
        }
    }

    void recursive(TreeNode* root) {
        if(!root) return;

        TreeNode* temp = root->right; //Save right node in temp
        root->right = root->left; //Copy left node to right
        root->left = NULL;
        TreeNode* ptr = root; //preserve root for traversal

        //Go to rightmost node of right
        while(ptr->right)
            ptr = ptr->right;

        ptr->right = temp; //Attach rightmost node to temp (right of current root)
        root = root->right; //Make right node of root as new root, and repeat
        recursive(root);
    }
};