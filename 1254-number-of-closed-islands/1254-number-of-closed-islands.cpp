class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool vis[101][101];
    int cant;
     void dfs(int i, int j,vector<vector<int>>&v){
       if(i<0 or j<0 or j>=v[0].size() or i>=v.size() or v[i][j] or  vis[i][j])return ;
         vis[i][j]=1;
         if(!i or !j or i==v.size()-1 or j==v[0].size()-1)cant=1;
         for(int k=0;k<4;++k)
             dfs(i+dx[k],j+dy[k],v);
     }
    
    
    int closedIsland(vector<vector<int>>& v) {
        // all zeros in middle 
        int ans=0;
        for(int i=0;i<v.size();++i){
            for(int j=0;j<v[0].size();++j){
                
                if(!vis[i][j]){
                cant=0;
                dfs(i,j,v);
                ans+= !cant && !v[i][j];
                }
            }
        }
        return ans;
    }
};