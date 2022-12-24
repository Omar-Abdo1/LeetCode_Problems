#define ll long long
class Solution {
public:
vector<vector<ll>>v;
ll n,mx,q;
map<pair<int,int>,ll>dp;

ll cn(int i, int p){
ll c=1;

if(dp.find({i,p})!=dp.end())return dp[{i,p}];

for(auto &j:v[i])if(j!=p){
    c+=cn(j,i);
}

dp[{i,p}]=c;
return c;
}

void dfs(int i, int p){
if(i!=p){
        ll res=1;

 for(auto &j:v[i]){
    res*=cn(j,i)*1ll;
 }

 if(res>mx){
   mx=res;
   q=1;
 }
 else if(res==mx)++q;

}

for(auto &j:v[i])if(j!=p)
    dfs(j,i);

}

    int countHighestScoreNodes(vector<int>& parents) {
       int n=parents.size();
        v=vector<vector<ll>>(n+1);
        for(int i=1;i<n;++i){
            int x=i,y=parents[i];
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(0,0);
        // try delete the rooooooooooot
        ll res=1;
for(auto &j :v[0]){
  res*=cn(j,0);  
}
   if(res>mx)return 1;
   else if(res==mx)return ++q;
   else return q;
    }
};