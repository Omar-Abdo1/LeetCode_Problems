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
    int sum=0;
    void dfs(TreeNode *cur){
            if(!cur)
                return;
              dfs(cur->right);
               sum+=cur->val;
              cur->val = sum;
              dfs(cur->left);
        }
    TreeNode* bstToGst(TreeNode* root) {        
        dfs(root);  
        return root;
    }
};