class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(3,1e9);
        dp[n%3] = 0;
        dp[(n-1)%3] = cost[n-1];
        for(int i=n-2;i>=0;--i){
            dp[i%3] = cost[i] + min(dp[(i+1)%3],dp[(i+2)%3]);
        }
       return min(dp[0],dp[1]);
    }
};