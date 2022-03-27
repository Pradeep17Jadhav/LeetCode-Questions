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
class FindElements {
public:
    bool bRoot = true;
    unordered_set<int> values;
    
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    void recover(TreeNode* root, int val)
    {
        if(!root) return;
        root->val = val;
        values.insert(val);
        recover(root->left, 2 * root->val + 1);
        recover(root->right, 2 * root->val + 2);
    }
    
    bool find(int target) {
        return values.count(target);
        //can also use this -
        //return values.find(target) != values.end()
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */