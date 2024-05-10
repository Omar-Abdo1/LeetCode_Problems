class Solution {
public:
    int maxProfit(vector<int>& v) {
      
      int n = v.size();
     vector<vector<int>>dp(2,vector<int>(3,-1000));

      for(int i=0;i<3;++i)dp[n%2][i] = 0;

      for(int i=n-1;i>=0;--i){
          dp[i%2][0] = max(-v[i]+dp[(i+1)%2][1],dp[(i+1)%2][0]);
          dp[i%2][1] = max(v[i]+dp[(i+1)%2][2],dp[(i+1)%2][1]);
           dp[i%2][2] = dp[(i+1)%2][0]; 
      }
        return dp[0][0];
    }
};