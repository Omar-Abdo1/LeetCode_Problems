class Solution {
public:
   int dp[201][201];
   int rec(int l,int r){
    if(l>=r) return 0;
    int &ret = dp[l][r];
    if(~ret)return ret;
     ret = 1e9;
     for(int k = l;k<=r;++k)
      ret=min(ret,k + max(rec(l,k-1) , rec(k+1,r)));
      return  ret;
   }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof dp);
        return rec(1,n);
    }
};