class Solution {
public:
   
    int maxSumDivThree(vector<int>& v) {
        int n = v.size();
        vector<int>dp(3,-1e9);
        dp[0] = 0;
        for(int i=n-1;i>=0;--i){
            vector<int>cur = dp;
           for(int j=0;j<3;++j){
            cur[j] = max(cur[j],v[i]+dp[(j+v[i])%3]);
           } 
           dp = cur;
        }
        return dp[0];
    }
};