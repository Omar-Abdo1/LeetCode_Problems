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
    int distributeCoins(TreeNode* root) {
       
        int ans = 0;
        function<int(TreeNode*)>dfs=[&](TreeNode* root)->int{
            int l=0,r=0;
            if(root->left!=NULL)
             l = dfs(root->left);
            if(root->right!=NULL)
             r = dfs(root->right);
            ans += abs(l) + abs(r);
            return l +  r + root->val-1;
        };
        dfs(root);
        return ans;
    }
};