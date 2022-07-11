class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                root = q.front();
                q.pop();
                
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            res.push_back(root->val);
        }

        return res;
    }
};