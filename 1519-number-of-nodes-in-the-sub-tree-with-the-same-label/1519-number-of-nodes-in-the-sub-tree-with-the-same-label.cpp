class Solution {
public:
    /// count from down to top 
    vector<int>cn,in,out,fr;
    vector<vector<int>>v;
    string s;
     void dfs(int i, int p){
     in[i]=fr[s[i]-'a']++;
      
     for(auto &j :v[i])if(j!=p){
         dfs(j,i);
     }
         
      cn[i]=fr[s[i]-'a']-in[i];   
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string t) {
        in=out=cn=vector<int>(n);
        v=vector<vector<int>>(n);
        fr=vector<int>(26);
        s=t;
        for(auto &x : edges){
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }
        dfs(0,0);
        return cn;
    }
};