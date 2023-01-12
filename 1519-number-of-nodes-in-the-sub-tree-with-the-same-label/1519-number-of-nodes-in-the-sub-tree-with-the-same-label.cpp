class Solution {
public:
    /// count from down to top 
    vector<int>cn;
    vector<vector<int>>v;
    string s;
    vector<int> dfs(int i, int p){
        vector<int>fr(27);
        fr[s[i]-'a']++;
        for(auto &j :v[i])if(j!=p){
            auto me = dfs(j,i);
            cn[i]+=me[s[i]-'a']; // (i) will increase by what the bottom substree from the same lable then (i) will return to (p) a vector which contains the frequncy until node (i)
            for(int k=0;k<26;++k)fr[k]+=me[k];
        }
        cn[i]=fr[s[i]-'a'];
        return fr;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string t) {
        cn=vector<int>(n);
        v=vector<vector<int>>(n);
        s=t;
        for(auto &x : edges){
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }
        auto me =dfs(0,0);
        return cn;
    }
};