class Solution {
public:
    int rec(int n){
        if(n==0)return 1;
        int op1,op2;
        op1=op2=-1e5;
        int ret=op1;
        if(n>=4) op1=4*rec(n-4);
        if(n>=3) op2=3*rec(n-3);
        return ret=max(op1,op2);
    }
    int integerBreak(int n) {
     int dp[n+9];
     dp[0]=1; 
     dp[2]=1;
     dp[3]=2;
     dp[4]=4;
     dp[5]=6;
     dp[6]=9;
    for(int i=7;i<=n;++i){
        dp[i]=max(dp[i-4]*4,dp[i-3]*3);
    }
        return dp[n];
    }
};


/*
2 --> 1,1
3 --> 2,1
4 --> 2,2
5 --> 3,2
6 --> 3,3
7  --> 3,4      12
8  --> 4,4      16
9  --> 3,3,3    27
10 --> 3,3,4    36
11 --> 3,4,4    48
12 --> 3,3,3,3  81
13 --> 3,3,3,4  108
14 --> 3,3,4,4
15 --> 3,3,3,3,3
16 --> 4,4,4,4

*/