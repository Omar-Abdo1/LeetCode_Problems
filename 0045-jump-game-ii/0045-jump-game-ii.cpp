class Solution {
public:
     

 int jump(vector<int>& nums) {
     int n=nums.size();
      vector<int>dp(n+1,1e8);   
      dp[n-1]=0;
    for(int i=n-2;i>=0;--i){
      
        for(int j=0;j<=nums[i] and i+j<=n-1 ;++j){
            dp[i]=min(dp[i],1+dp[i+j]);
       }
        
    }
     return dp[0];     
}
};