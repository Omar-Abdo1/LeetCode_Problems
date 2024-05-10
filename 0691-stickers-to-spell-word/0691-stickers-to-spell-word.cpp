class Solution {
public:
   bool getBit(int msk,int idx){
     return ((msk>>idx)&1) ;
   }
   
       void Match(int &msk,string &s,string &t){
         for(int i=0;i<t.size();++i){
            for(int j=0;j<s.size();++j){
                 if(s[j]==t[i] && getBit(msk,j)==0)
                  {msk|=(1<<j); break;}
            }
         }
    }
    int minStickers(vector<string>& v, string s) {
          int n = s.size();
       vector<int>dp(1<<n,1e9);
       dp[0] = 0;
       for(int msk=0;msk<1<<n;++msk){
            for(auto &w : v){
                 int cur = msk;
                 Match(cur,s,w);
                 if((cur|msk)!=msk)
                 dp[cur]=min(dp[cur],1+dp[msk]);
            }          
       }
     return dp.back()==1e9 ? -1 : dp.back();
    }
};