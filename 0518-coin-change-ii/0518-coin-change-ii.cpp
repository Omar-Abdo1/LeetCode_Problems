class Solution {
public:
    vector<int>v;
    int k;
    int dp[5005][305];
    int rec(int rem,int i){
        if(rem==0)return 1;
        if( rem<0 or i==v.size())return 0;
      if(~dp[rem][i])return dp[rem][i];
        return dp[rem][i]=rec(rem-v[i],i)+rec(rem,i+1);
    }
    int change(int amount, vector<int>& coins) {
        k=amount;
        v=coins;
        memset(dp,-1,sizeof dp);
    return rec(k,0);
    }
};