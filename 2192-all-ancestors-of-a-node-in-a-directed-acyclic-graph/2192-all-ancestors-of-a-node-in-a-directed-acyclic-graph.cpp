class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>ans(n);
        vector<bool>vis(n);
        vector<vector<int>>adj(n);
        for(auto &e : edges)
            adj[e[0]].push_back(e[1]);
         function<void(int,int)>dfs=[&](int node,int cur){
             for(auto &j : adj[node])if(ans[j].empty() || ans[j].back()!=cur) {
                 ans[j].push_back(cur);
                 dfs(j,cur);
             }
         };
         for(int i=0;i<n;++i)
             dfs(i,i);
        
        return ans;
           
    }
};