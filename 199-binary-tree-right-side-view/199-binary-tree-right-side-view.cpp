class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<queue<TreeNode*>>q;
        queue<TreeNode*> prev;
        prev.push(root);
        q.push(prev);
        
        while(!q.empty()) {
            prev = q.front();
            q.pop();
            res.push_back(prev.back()->val);
            queue<TreeNode*> curr;
            while(!prev.empty()) {
                root = prev.front();
                prev.pop();
                
                if(root->left)
                    curr.push(root->left);
                if(root->right)
                    curr.push(root->right);
            }
            if(curr.size())
                q.push(curr);
        }

        return res;
    }
};