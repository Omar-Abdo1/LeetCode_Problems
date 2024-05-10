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
    int sumNumbers(TreeNode* root) {
        function<int(TreeNode*,int)>dfs=[&](TreeNode*root,int sum){
            if(root->left==nullptr && root->right==nullptr)
              return sum;
              int ret = 0;
               if(root->left!=nullptr)
              ret+=dfs(root->left,sum*10 + root->left->val);
               if(root->right!=nullptr)
              ret+=dfs(root->right,sum*10 + root->right->val);
                return ret;
        };
        return dfs(root,root->val);
    }
};