class Solution {
    private :
    int dp[101][27];
public:
    string s;
    bool valid(string t){
        for(int i=0;i<t.size()-1;++i)
            if(t[i]=='0')return 0;
     int me=stoi(t);
        return me && me<=26;
    }
    int rec(int i, int ya){
       if(i==s.size())return 1;
      int &ret=dp[i][ya];
        if(~ret)return ret;
        ret=0;
        string cur="";
        for(int j=i;j<s.size();++j){
            cur+=s[j];
            if(cur.size()<=2 && valid(cur)){
                ret+=rec(i+cur.size(),stoi(cur));
            }
        }
        return ret;
    }
    
    
    int numDecodings(string t) {
        s=t;   
        memset(dp,-1,sizeof dp);
        return rec(0,0);
    }
};