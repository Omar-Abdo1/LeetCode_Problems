class Solution {
public:
    int maximalSquare(vector<vector<char>>& v) {
      int n=v.size();
        int m=v[0].size();
        int dp[n+2][m+2];
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(v[i-1][j-1]-'0');
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        int l=1,r=min(n,m),mid,ans=0;
        while(l<=r){
         mid=(l+r)/2;
         bool ok=0;
        for(int i=1;i+mid-1<=n && !ok ;++i){
            for(int j=1;j+mid-1<=m;++j){
            int x=i+mid-1;
                int y=j+mid-1;
             int sum=dp[x][y]-dp[x][j-1]-dp[i-1][y]+dp[i-1][j-1];   
              if(sum==mid*mid){
                  ok=1;
                  break;
              }  
            }
        }
            if(ok){
                ans=mid*mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
            
        }
        return ans;
        
        
        
        
    }
};