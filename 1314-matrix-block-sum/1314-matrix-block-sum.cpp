class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& v, int k) {
        int n=v.size();
        int m=v[0].size();
        int dp[n+2][m+2];
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+v[i-1][j-1];
            }
        }
       vector<vector<int>>ans;
        for(int i=1;i<=n;++i){
            vector<int>t;
            for(int j=1;j<=m;++j){
               int lr=i-k;
               int rr=i+k;
                int lc=j-k;
                int rc=j+k;
                while(lr<=0)++lr;
                while(lc<=0)++lc;
                while(rr>n)--rr;
                while(rc>m)--rc;
            int sum=dp[rr][rc]-dp[rr][lc-1]-dp[lr-1][rc]+dp[lr-1][lc-1];    
                t.push_back(sum);
            }
            ans.push_back(t);
        }
        return ans;
        
    }
};