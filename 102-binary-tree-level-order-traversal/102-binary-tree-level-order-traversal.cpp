class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)
            return res;
        
        queue<TreeNode*> q; //queue for storing nodes in level order
        q.push(root);
        while(!q.empty()) 
        {
            vector<int>temp; //temp vector to store values at current level
            int count = q.size();
            
            //get all elements at curr level, add their values in temp array, and add their childs in the queue
            while(count--)
            {
                root = q.front();
                q.pop();
                temp.push_back(root->val);
                
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);

            }
            res.push_back(temp); //push temp vector of current level in the result
        }
        return res;
    }
};