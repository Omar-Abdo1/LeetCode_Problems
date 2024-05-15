class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool ok;
    vector<vector<int>>dist,vis;
    void rec(int i,int j,int mx){
       if(i<0 or j<0 or i>=dist.size() or j>=dist.size() or dist[i][j]<mx or vis[i][j] or ok)
           return ;
        if(i==dist.size()-1 && j==dist.size()-1)
        {
            ok = 1;
            return;
        }
        vis[i][j]=1;
        for(int k=0;k<4;++k){
            rec(i+dx[k],j+dy[k],mx);
        }
        //vis[i][j]=0;
        return ;
    }
    int maximumSafenessFactor(vector<vector<int>>& v) {
        int n=v.size();
        dist=vector<vector<int>>(n,vector<int>(n,-1));
        queue<pair<int,int>>qu;
        for(int i=0;i<n;++i){
             for(int j=0;j<n;++j){
                 if(v[i][j]){
                     qu.push({i,j});
                     dist[i][j]=0;
                 }
             }
        }
        int l=0,r=0,mid,ans=0;
         while(!qu.empty()){
             auto[i,j]=qu.front();
             qu.pop();
             for(int k=0;k<4;++k){
                 int x = i+dx[k];
                 int y = j+dy[k];
                 if(x>=0 && x<n && y>=0 &&y<n && dist[x][y]==-1){
                     dist[x][y]=1+dist[i][j];
                     r=max(r,dist[x][y]);
                     qu.push({x,y});
                 }
             }
         }
        function<bool(int)>can=[&](int mid)->bool{
            ok = 0;
            vis=vector<vector<int>>(n,vector<int>(n)); 
            rec(0,0,mid);
            return ok;
        };
        while(l<=r){
            mid = l+r>>1;
            can(mid) ? ans=mid,l=mid+1 : r=mid-1;
        }
        return ans;
    }
};