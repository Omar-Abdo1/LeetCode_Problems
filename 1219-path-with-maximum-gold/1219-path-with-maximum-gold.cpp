class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    bool vis[21][21];
    int n,m;
    int rec(int i,int j,vector<vector<int>>&v){
        int ret = 0;
        vis[i][j]=1;
        for(int k=0;k<4;++k)
        {
            int x = dx[k] + i;
            int y = dy[k] + j;
            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && v[x][y]){
                ret=max(ret,v[x][y]+rec(x,y,v));
                vis[x][y]=0;
            }
        }
        return ret;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
        int ans = 0;  
        for(int i=0;i<n;++i){
             for(int j=0;j<m;++j){
                 if(grid[i][j]){
                     memset(vis,0,sizeof vis);
                     ans=max(ans,grid[i][j]+rec(i,j,grid));
                 }
             }
        }
        return ans;
    }
};