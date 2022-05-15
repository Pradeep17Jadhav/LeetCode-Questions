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
    int sum = 0;
    int maxDepth = 0;
    int deepestLeavesSum(TreeNode* root) {
        return deepestLeavesSumIterative(root);
        // findSum(root, 1);
        // return sum;
    }
    
    int deepestLeavesSumIterative(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        
        while(!q.empty()) {
            res = 0;
            int n = q.size();
            
            //for all nodes in current depth, add the all child nodes in the queue.
            //when the queue will become empty, we can consider that the current depth is the deepest.
            for(int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                res += curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return res;
    }

    void findSum(TreeNode* node, int currDepth)
    {
        if(!node)
            return;
        
        if(currDepth > maxDepth)
        {
            maxDepth = currDepth;
            sum = 0;
        }

        if(currDepth == maxDepth)
            sum += node->val;

        findSum(node->left, currDepth + 1);
        findSum(node->right, currDepth + 1);
    }
};