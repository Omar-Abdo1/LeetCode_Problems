class Solution {
    private :
    int dp[202][205];
public:
    int minimumTotal(vector<vector<int>>& v) {
     memset(dp,0,sizeof dp);
        int n=v.size();
        
     for(int i=0;i<v[n-1].size();++i)dp[n-1][i]=v[n-1][i];
    
        for(int i=n-2;i>=0;--i){
          for(int j=0;j<v[i].size();++j){
           
             dp[i][j]=v[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
                
          }  
        }
        
        return dp[0][0];
        
        
        
    }
};