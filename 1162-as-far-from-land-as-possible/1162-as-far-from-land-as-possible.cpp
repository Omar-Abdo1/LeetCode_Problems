class Solution {
public:
      int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool vis[101][101];
    int maxDistance(vector<vector<int>>& v) {
      
        queue<pair<int,int>>qu;
        for(int i=0;i<v.size();++i){
            for(int j=0;j<v[0].size();++j){
                if(v[i][j])qu.push({i,j}),vis[i][j]=1;
            }
        }
        if(v.size()*v[0].size()-qu.size()==0 || !qu.size())return -1;
        int dep=0;
        while(!qu.empty()){
            int sz=qu.size();
            while(sz--){
                auto [x,y]=qu.front();
                qu.pop();
                for(int i=0;i<4;++i){
                    int nx=dx[i]+x;
                    int ny=dy[i]+y;
                    if(nx<0 or ny<0 or nx>=v.size() or ny>=v[0].size() || vis[nx][ny])continue;
                    vis[nx][ny]=1;
                    qu.push({nx,ny});
                }
            }
            if(qu.size())
            dep++;
        }
        return dep;
    }
};