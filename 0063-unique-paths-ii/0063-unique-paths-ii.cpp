class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n= v.size();
        int m=v[0].size();
        long long dp[n+1][m+1];
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        if(v[0][0])dp[0][0]=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(v[i][j])continue;
                
                if(i-1>=0)dp[i][j]+=dp[i-1][j];
                if(j-1>=0)dp[i][j]+=dp[i][j-1];
            }
        }
      
        return dp[n-1][m-1];
    }
};