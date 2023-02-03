class Solution {
public:
    int k;
    vector<int>v;
  vector<int>dp;
    int solve(int rem){
        if(rem==0)return 0;
         int &ret=dp[rem];
        if(~ret)return ret;
         ret=1e9;
        for(int j=0;j<v.size();++j){
            if(rem-v[j]>=0){
               ret=min(ret,1+solve(rem-v[j])); 
            }
        }
     return ret;
    }
    int coinChange(vector<int>& coins, int amount) {
    v=coins;
        k=amount;
        if(!k)return k;
        dp=vector<int>(k+1);
        dp[0]=0;
       for(int i=1;i<=k;++i){
           dp[i]=1e9;
         for(int j=0;j<v.size();++j){
           
             if(i-v[j]>=0)
                 dp[i]=min(dp[i],dp[i-v[j]]+1);
         }  
           
       }
        if(dp[k]==1e9)dp[k]=-1;
        return dp[k];
        
        
    }
};