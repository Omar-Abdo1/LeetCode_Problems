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
    bool evaluateTree(TreeNode* root) {
        
        function<bool(TreeNode*)>dfs=[&](TreeNode* root)->bool{
           
            if(root->left==NULL && root->right==NULL)
                 return root->val;
            bool l = dfs(root->left);
            bool r = dfs(root->right);
            return root->val==2? l|r : l&r;
        };
        
        return dfs(root);
    }
};