class Solution {
public:
    set<string>st;
    string s;
    int dp[301];
    bool rec(int idx){
        
    if(idx==s.size())return 1;
    else if(idx>s.size())return 0; 
        string cur="";
        int &ans=dp[idx];
        if(~ans)return ans;
        ans=0;
      for(int i=idx;i<s.size();++i){
            cur+=s[i];
          if(st.find(cur)!=st.end()){
              ans|=rec(idx+cur.size());
              if(ans)return 1;
          }
      }
        return ans;
    }
    bool wordBreak(string t, vector<string>& v) {
        for(auto &i :v)st.insert(i);
        s=t;
        memset(dp,-1,sizeof dp);
        return rec(0);
    }
};