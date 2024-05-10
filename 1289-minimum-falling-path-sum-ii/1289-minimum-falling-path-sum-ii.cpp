class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
          int n = grid.size(),m=grid[0].size();
            int dp[m+1];
            memset(dp,0,sizeof dp);
         for(int i=n-1;i>=0;--i){
              int nxt[m+1];
             for(int j=0;j<=m;++j){
                nxt[j] = 1e9;
                 for(int k=0;k<m;++k){
                     if(j!=k)
                     nxt[j] = min(nxt[j],grid[i][k]+dp[k]);
                 }
             }
            for(int j=0;j<=m;++j)
            dp[j] = nxt[j];
         }
         return dp[m];
    }
};