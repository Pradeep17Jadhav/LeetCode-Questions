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
    int depth = 0;
    vector<int>nodes;
    //TC: O(2N)
    //SC: O(N) for vector
    TreeNode* balanceBST(TreeNode* root) {
        //traverse through all elements in-order
        inorderTraverse(root);
        
        //create a new BST from sorted array
        return createBST(0, nodes.size()-1);
    }
    
    TreeNode* createBST(int start, int end)
    {
        if(start > end)
            return NULL;

        int mid = (start + end)/2;
        TreeNode* root = new TreeNode(nodes[mid]); //assign value of mid index to current root
        root->left = createBST(start, mid-1); //create left subtree from indices on left
        root->right = createBST(mid+1, end); //create right subtree from indices on right
        return root;
    }
    
    void inorderTraverse(TreeNode* root)
    {
        if(!root)
            return;
        
        inorderTraverse(root->left);
        nodes.push_back(root->val); //add in a vector. this is a BST, so all values in vector are sorted
        inorderTraverse(root->right);
    }
};