class Solution {
public:
     int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int cant;
     void dfs(int i, int j,vector<vector<int>>&v1,vector<vector<int>>&v2){
       if(i<0 or j<0 or j>=v1[0].size() or i>=v1.size() or !v1[i][j])return ;
         if(!v2[i][j])cant=1; // this connected comp can not be sub from grid 1
         v1[i][j]=0;
         for(int k=0;k<4;++k)
             dfs(i+dx[k],j+dy[k],v1,v2);
     }
    int countSubIslands(vector<vector<int>>& v1, vector<vector<int>>& v2) {
        // if all v2 in v1 so ok dfs from v1 
        swap(v1,v2);
        int ans=0;
        for(int i=0;i<v1.size();++i){
            for(int j=0;j<v1[0].size();++j){
                if(v1[i][j]){
                    cant=0;
                    dfs(i,j,v1,v2);
                    ans+=!cant;
                }
            }
        }
        return ans;
    }
};