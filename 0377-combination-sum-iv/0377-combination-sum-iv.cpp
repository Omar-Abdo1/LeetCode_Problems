class Solution {
public:
    int combinationSum4(vector<int>& v, int k) {
        int n=v.size();
       int dp[k+2];
        dp[0]=1;
        for(int sz=1;sz<=k;++sz){
           dp[sz]=0;
            for(int i=0;i<n;++i){
                if(sz>=v[i]){
                    long long me=dp[sz-v[i]];
                    dp[sz]+=me;
                }
            }
        }
        return dp[k];
    }
};