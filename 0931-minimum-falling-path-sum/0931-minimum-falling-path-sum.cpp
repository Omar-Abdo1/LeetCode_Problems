class Solution {
public:
 int minFallingPathSum(vector<vector<int>>& v) {
    int n=v.size(),m=v[0].size();
  int dp[n+2][m+2];
     for(int i=0;i<m;++i)dp[0][i]=v[0][i];
     int ans=1e9;
   for(int i=1;i<n;++i){
       for(int j=0;j<m;++j){
          int ret=dp[i-1][j];
          if(j+1<m)ret=min(ret,dp[i-1][j+1]);
          if(j-1>=0)ret=min(ret,dp[i-1][j-1]); 
           dp[i][j]=ret+v[i][j];
       }
   }
     for(int i=0;i<m;++i)
         ans=min(ans,dp[n-1][i]);
     return ans;
     
     
     
     
    }
};