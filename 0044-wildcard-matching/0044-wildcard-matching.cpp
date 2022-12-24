class Solution {
public:
string s,t;
vector<vector<int>>dp;
 int solve(int i,int j){
 if(i==s.size() && j==t.size())return 1; // both string ends 
 if(i==s.size()){
     // if the remaining chars are * we can delete them
     if(t[j]=='*')return solve(i,j+1);
     return 0;
 }
 if(j==t.size()) return 0; // second end but the first did not yet 
 int &res=dp[i][j];
 if(~res)return res;
 res=0;
 if(s[i]==t[j] || t[j]=='?')res|=solve(i+1,j+1) ;// match or i have  ? 
 else if(t[j]=='*'){
    res|=solve(i,j+1); // enough * 
     res|=solve(i+1,j); // * take more char from the first 
 }
 return res;
 }
    bool isMatch(string q, string qq) {
    s=q,t=qq;
    dp=vector<vector<int>>(s.size(),vector<int>(t.size(),-1));
   return solve(0,0);
    }
};