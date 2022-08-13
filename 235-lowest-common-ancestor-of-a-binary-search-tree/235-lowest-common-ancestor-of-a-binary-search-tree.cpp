class Solution {
public:
    //We will take advantage of the tree being a BST
    //if values of both the P and Q is less the root, we will move to left subtree and ignore right subtree
    //If values of both the P and Q is grater than the root, we will move to right subtree
    //When P and Q and either lesser or greater than root, we can consider the current root as lowest common ancestor
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};