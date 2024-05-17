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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
       
         function<TreeNode*(TreeNode*)>dfs=[&](TreeNode* root)->TreeNode*{
             
              if(root->left==NULL && root->right==NULL)
              {
                   if(root->val==target)
                        return NULL;
                  else return root;
              }
             if(root->left!=NULL)
             root->left = dfs(root->left);
             if(root->right!=NULL)
             root->right=dfs(root->right);
             if(root->left==NULL && root->right==NULL)
              {
                   if(root->val==target)
                        return NULL;
                  else return root;
              }
             return root;
         };
        root = dfs(root);
        return root;
        
    }
};