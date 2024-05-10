class Solution {
public:
  int total=0;
    bool canPartition(vector<int>& nums) {
       for(auto &i : nums)
       total += i;

       if(total&1)
       return 0;
       
      int n =nums.size();
       bool dp[2][total+1];

         for(int j=0;j<=total;++j)
         dp[n&1][j] = total==2*j;  

        for(int i=n-1;i>=0;--i){
             for(int j=total;j>=0;--j){
                 dp[i&1][j] = dp[(i+1)&1][j];
                 if(j+nums[i]<=total)
                 dp[i&1][j]|=dp[(i+1)&1][j+nums[i]];
             }
        }
         return dp[0][0];  
    }
};