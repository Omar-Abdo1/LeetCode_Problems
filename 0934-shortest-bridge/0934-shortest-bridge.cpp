class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool vis[101][101],vis2[101][101];
     void dfs(int i, int j,vector<vector<int>>&v){
       if(i<0 or j<0 or j>=v[0].size() or i>=v.size() or !v[i][j] or vis[i][j])return ;
         vis[i][j]=1;
          for(int k=0;k<4;++k)
             dfs(i+dx[k],j+dy[k],v);
     }
    int shortestBridge(vector<vector<int>>& v) {
        // given two islands 
        bool get=0;
        for(int i=0;i<v.size() && !get ;++i){
            for(int j=0;j<v[0].size();++j){
                if(v[i][j]){
                    dfs(i,j,v);
                    get=1;
                    break;
                }
            }
        }
        queue<pair<int,int>>qu;
        for(int i=0;i<v.size();++i){
            for(int j=0;j<v[0].size();++j){
                if(v[i][j] && !vis[i][j]){
                    qu.push({i,j});
                    vis2[i][j]=1;
                }
            }
        }
        int dep=-1;
        while(!qu.empty()){
            int sz=qu.size();
            while(sz--){
             auto [x,y]=qu.front();
             qu.pop();
             if(vis[x][y])return dep;
             for(int k=0;k<4;++k){
                 int i=x+dx[k];
                 int j=y+dy[k];
          if(i<0 or j<0 or j>=v[0].size() or i>=v.size() or vis2[i][j])continue ;
              vis2[i][j]=1;
              qu.push({i,j});
             }
            }
            dep++;
        }
        return 0;


    }
};