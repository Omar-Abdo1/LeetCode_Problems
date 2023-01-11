class Solution {
public:
    long long cnt;
    vector<vector<int>>v;
    vector<bool>ok;
    void dfs(int i,int p,vector<bool>&go){
        
        for(auto &j:v[i])if(j!=p){
            dfs(j,i,go);
        }
        if(go[i] && i!=p)
            go[p]=1;
    }
    
     void dfs2(int i,int p,vector<bool>&go){
        cnt+=go[i];
        for(auto &j:v[i])if(j!=p){
            dfs2(j,i,go);
        }
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        v=vector<vector<int>>(n);
        ok=vector<bool>(n);
        for(auto &x :edges){
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }
        dfs(0,0,hasApple);
        dfs2(0,0,hasApple);
        if(--cnt*2>0)return 2*cnt; // edges :)
        return 0;
    }
};