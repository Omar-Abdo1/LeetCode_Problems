class Solution {
public:
bool getBit(int msk,int idx){
    return (msk>>idx)&1;
}
    int dp[12][1<<12|1];
    int rec(int i,int msk,vector<int>&v,int &k){
        if(msk+1==1<<(int)v.size())
          return -1e9;
          if(i==k)
           return 1e9;
           int &ret = dp[i][msk];
           if(~ret)return ret;
           ret = 1e9;
            int temp = ((1<<(int)v.size())-1)^msk;
           for(int cur=temp;cur;cur=temp&(cur-1)){
               int sum = 0;
               for(int j=0;j<v.size();++j)
                 if(getBit(cur,j))
                 sum+=v[j];
                 ret = min(ret,max(sum,rec(i+1,msk|cur,v,k)));
           }
           return ret;
    }
    int minimumTimeRequired(vector<int>& v, int k) {
        memset(dp,-1,sizeof dp);
        return rec(0,0,v,k);
    }
};