class Solution {
public:
string s;
int dp[1001][1001];
int rec(int i, int j){
if(i>j)return 0;
else if(i==j)return 1;
else if(i+1==j)return 1+(s[i]==s[j]);
int &ret=dp[i][j];
if(~ret)return ret;
ret=0;
if(s[i]==s[j])
return ret=2+rec(i+1,j-1);
return ret=max(rec(i+1,j),rec(i,j-1)); 
}
    int longestPalindromeSubseq(string t) {
        s=t;
        memset(dp,-1,sizeof dp);
        return rec(0,s.size()-1);
    }
};