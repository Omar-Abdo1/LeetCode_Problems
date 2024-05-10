class Solution {
public:
     bool getBit(int msk,int idx){
        return (msk>>idx)&1;
     }
    vector<char>v;
    int dp[11][2][2][2][1<<10|1];
    int rec(int i,bool sm,bool non_zero,bool ok,int msk){
        if(i==v.size())
         return ok;
         int &ret = dp[i][sm][non_zero][ok][msk];
         if(~ret)return ret;
         ret = 0;
         int ed = sm ? 9 : v[i]-'0' ; 
         for(int dig=0;dig<=ed;++dig){
            int temp = msk;
            bool t1 = ok , t2 = non_zero;
            if(dig) t2 = 1;
            if(t2){
                if(getBit(temp,dig))t1=1;
                else temp|=(1<<dig);
            }
             ret+=rec(i+1,sm|(dig<v[i]-'0'),t2,t1,temp);
         }
         return ret;
    }
    int numDupDigitsAtMostN(int n) {
        while(n){
            v.push_back(n%10 + '0');
            n/=10;
        }
        reverse(v.begin(),v.end());
        memset(dp,-1,sizeof dp);
        return rec(0,0,0,0,0);
    }
};