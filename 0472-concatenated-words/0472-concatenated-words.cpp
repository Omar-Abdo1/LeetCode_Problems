class Solution {
public:
    set<string>st;
    int solve(int idx,string s){
    if(idx==s.size())return 0;
     string cur="";
         int ret=-1e9;
        for(int i=idx;i<s.size();++i){
            cur+=s[i];
            if(st.find(cur)!=st.end()){
                ret=max(ret, 1+solve(idx+cur.size(),s) );
            }
        }
        return ret;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto & s :words)st.insert(s);
        vector<string>ans;
            for(auto &s : words)
            if(solve(0,s)>1)
            ans.push_back(s);
        return ans;      
    }
};