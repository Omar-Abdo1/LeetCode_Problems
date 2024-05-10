class Solution {
public:

   int n,m;
   int dx[3]={1,-1,0};
   int dp[71][71][71];
   int rec(int i,int j,int jj,vector<vector<int>>&v){  
     
     if(i==n) return 0;

     int &ret = dp[i][j][jj];
     if(~ret)return ret;
     ret = -1e9;
     for(int k=0;k<3;++k){
         for(int kk=0;kk<3;++kk){
             int x = j + dx[k];
             int xx = jj + dx[kk];
             if(x>=0 && x<m  && xx>=0 && xx<m){
                 ret = max(ret ,(j==jj ? v[i][j] : v[i][j]+v[i][jj])  + rec(i+1,x,xx,v));
             }
         }
     }
     return ret;
   }

    int cherryPickup(vector<vector<int>>& v) {
         n = v.size() , m = v[0].size();
         memset(dp,-1,sizeof dp);
        return rec(0,0,m-1,v);
    } 

};