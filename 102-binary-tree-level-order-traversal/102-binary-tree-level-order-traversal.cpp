class Solution {
public:
    queue<TreeNode*> q;
    vector<vector<int>>res;
    vector<int>temp;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return res;
        
        q.push(root);
        int childCount = 1;
        while(!q.empty()) {
            int count = childCount;
            childCount = 0;
            
            while(count--) {
                root = q.front();
                q.pop();
                temp.push_back(root->val);
                
                if(root->left) {
                    q.push(root->left);
                    childCount++;
                }
                if(root->right) {
                    q.push(root->right);
                    childCount++;
                }

            }
            res.push_back(temp);
            temp.clear();
        }
        
        return res;

    }
        
};