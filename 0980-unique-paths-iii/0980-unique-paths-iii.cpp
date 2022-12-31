class Solution {
public:
int all;
bool vis[21][21];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int cn;
int me;
void rec(int i, int j,vector<vector<int>>&v){
 if(i<0 or j<0 or i>=v.size() or j>=v[0].size() or v[i][j]==-1 or vis[i][j])return;
 if(v[i][j]==2){
     cn+=(me-1==all);
     return ;
 }
 me++;
 vis[i][j]=1;
 for(int k=0;k<4;++k){
     rec(i+dx[k],j+dy[k],v);
 }
 me--;
 vis[i][j]=0;
}
    int uniquePathsIII(vector<vector<int>>& v) {
         int ii,jj;
        for(int i=0;i<v.size();++i){
            for(int j=0;j<v[0].size();++j){
               if(v[i][j]==1)ii=i,jj=j;
               if(!v[i][j])all++;
            }
        }
        rec(ii,jj,v);
        return cn;
    }
};