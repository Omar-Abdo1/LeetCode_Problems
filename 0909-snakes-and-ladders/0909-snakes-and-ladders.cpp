class Solution {
public:
bool vis[21*21];
pair<int,int> get(int cur,int n){
 int row=cur/n;
 if(cur%n)++row;
 row=n-row;
 int mx=(n-row)*n;
 int col;
 int x= n&1 ? 0 : 1 ; 
 if(row%2==x){
 col= n-(mx-cur+1);
 }
 else{
 col= mx-cur;
 }
return {row,col};
}
int snakesAndLadders(vector<vector<int>>& v) { 
 int n=v.size();
queue<int>qu;
 qu.push(1);
 vis[1]=1;
 int dep=0;
 while(!qu.empty()){
     int sz=qu.size();
     while(sz--){
      int me=qu.front();
      qu.pop();
     if(me==n*n)return dep;
     for(int i=1;i<=6;++i){
         int cur=min(me+i,n*n);
         auto [x,y] = get(cur,n);
         int can;
         v[x][y]==-1 ? can=cur : can=v[x][y];
         if(!vis[can]){
             vis[can]=1;
             qu.push(can);
         }
     }
     }
     ++dep;
 }
return -1;
}

};