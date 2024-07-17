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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        set<int>st(to_delete.begin(),to_delete.end());
        
        vector<TreeNode*>ans;
        function<TreeNode*(TreeNode*)>dfs=[&](TreeNode* cur)->TreeNode*{
             if(cur->left!=NULL) 
            cur->left = dfs(cur->left);
            if(cur->right!=NULL)
             cur->right = dfs(cur->right);
            
            if(st.count(cur->val)){
                if(cur->left!=NULL)
                    ans.push_back(cur->left);
                if(cur->right!=NULL)
                    ans.push_back(cur->right);
                return NULL;
            }
            else return cur;
        };
        dfs(root);
        if(!st.count(root->val))ans.push_back(root);
        return ans;
        
    }
};