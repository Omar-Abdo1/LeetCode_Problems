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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode *Bin = new TreeNode;
        map<int,int>par,child;
        map<int,vector<pair<int,int>>>mp;
        for(auto &v :descriptions){
            ++par[v[0]];
            ++child[v[1]];
            mp[v[0]].push_back({v[1],v[2]});
        }
        for(auto &[p,v] : par)
            if(!child[p]){
                Bin->val = p;
                break;
            }
        function<TreeNode*(TreeNode*)>dfs=[&](TreeNode* cur){
            int val = cur->val;
            for(auto &p : mp[val])
            {
                if(p.second)
                    cur->left = dfs( new TreeNode(p.first ) );
                else cur->right = dfs( new TreeNode(p.first) );
            }
            return cur;
        };
        dfs(Bin);
        return Bin;
    }
};