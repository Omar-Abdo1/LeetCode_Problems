class Solution {
public:
    int dp[5005];
    int change(int k, vector<int>& v) {
       dp[0]=1;
        int n=v.size();
        for(int i=0;i<n;++i){
          
            for(int j=1;j<=k;++j){
                if(j>=v[i])
                    dp[j]+=dp[j-v[i]];
            }
        }
        return dp[k];        
    }
};