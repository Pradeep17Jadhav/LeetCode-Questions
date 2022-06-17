class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int res = 0;
        int rootCovered = dfs(root, res);
        if(rootCovered == 0) //handle case having single node 'root' - [0]
            res++;
        
        return res;
    }

    //Return 0 if curr node is a leaf, not camera attached.
    //Return 1 if curr node is a parent of a leaf, with a camera on this (current) node.
    //Return 2 if curr node is coverd by camera of other nodes, without a camera on this node
    int dfs(TreeNode* root, int &res) {
        if (!root) 
            return 2;

        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        
        //if any of the childs is a leaf, attach a camera at current node
        if(left == 0 || right == 0) {
            res++;
            return 1;
        }

        //if either left or right node returns 1, they have camera installed so current node is covered
        if(left == 1 || right == 1)
            return 2;
        else
            return 0;
    }
};