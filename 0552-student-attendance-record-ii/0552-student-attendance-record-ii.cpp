class Solution {
    public:
    int mod = 1e9+7;
    int add(int a,int b){
      return (0LL + a%mod + b%mod +mod)%mod;
  }
     int n;
     int dp[100005][3][3][2];
     int rec(int idx,int lst,int prv,bool A){
         if(idx==n)
             return 1;
         int &ret = dp[idx][lst][prv][A];
         if(~ret)return ret;
         ret=0;
         if(lst==0){ // A 
             ret=add(ret,rec(idx+1,1,lst,A)); // AP
             ret=add(ret,rec(idx+1,2,lst,A)); // AL
         }
         if(lst==1){ // P
             if(!A)
          ret=add(ret,rec(idx+1,0,lst,1)); // PA
          ret=add(ret,rec(idx+1,1,lst,A)); // PP
          ret=add(ret,rec(idx+1,2,lst,A)); // PL  
         }
         if(lst==2){ // L
             if(!A)
            ret=add(ret,rec(idx+1,0,lst,1));  // LA
            ret=add(ret,rec(idx+1,1,lst,A)); // LP
            if(prv!=lst)
                ret=add(ret,rec(idx+1,2,2,A)); // LL
         }
         return ret%mod;
     }
    int checkRecord(int x) {
       n = x;
        memset(dp,-1,sizeof dp);
       int op1 = rec(1,0,0,1);
       int op2 = rec(1,1,0,0);
       int op3 = rec(1,2,0,0);
       op1 = add(op1,op2);
       op1=add(op1,op3);
        return op1;
    }
};

/*

A + (P or L) 
P + (A or L)
L + (A or P or L)




define dp[i][p] number of recoreds with lenght i such that the last char is p

p ->
0 A
1 L
2 P

dp[0]



*/