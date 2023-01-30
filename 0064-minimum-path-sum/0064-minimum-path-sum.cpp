class Solution {
public:
    int minPathSum(vector<vector<int>>& v) {
      int n=v.size();
        int m=v[0].size();
        int dp[n+1][m+1];
         dp[0][0]=v[0][0];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!i and !j)continue;
                int ret=1e9;
                if(i-1>=0)ret=min(ret,dp[i-1][j]);
                if(j-1>=0)ret=min(ret,dp[i][j-1]);
                dp[i][j]=v[i][j]+ret;
            }
        }
        return dp[n-1][m-1];
        
        
    }
};