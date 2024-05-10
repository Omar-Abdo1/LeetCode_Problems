class Solution {
public:
  int req,k;
  vector<int>v;
  int dp[16][1<<16];
  int rec(int idx,int msk){
     if(!msk)
      return idx==k;
      int &ret=dp[idx][msk];
      if(~ret)return ret;
      ret=0;
      for(int tmp=msk;tmp;tmp=msk&(tmp-1)){
         int sum =0;
         for(int i=0;i<v.size();++i){
             if((tmp>>i)&1)
              sum+=v[i];
              if(sum>req)break;
         }
         if(sum==req){
          ret|=rec(idx+1,msk^tmp);
         }
         if(ret)return ret;
      }
      return ret;
  }
    bool canPartitionKSubsets(vector<int>& nums, int q) {
        v = nums;
        k = q;
        req = accumulate(v.begin(),v.end(),0);
        if(req%k)return 0;
        req/=k;
        memset(dp,-1,sizeof dp);
        return rec(0,(1<<(int)v.size()) - 1);
    }
};