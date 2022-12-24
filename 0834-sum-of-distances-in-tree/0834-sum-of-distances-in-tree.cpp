class Solution {
public:
vector<int>can;
vector<vector<int>>v;
vector<int>dis;
int m;
void dfs1(int i, int p){

for(auto &j:v[i])if(j!=p)
    dfs1(j,i);
if(i!=p)
can[p]+=can[i]+1;
}

void dfs2(int i, int p){
if(i!=p)dis[i]=dis[p]-can[i]+(m-can[i]-1)-1;
for(auto &j:v[i])if(p!=j)
dfs2(j,i);
}

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    m=n;
    v=vector<vector<int>>(n+1);
    dis=vector<int>(n);
    can=vector<int>(n+1); 
    for(auto &x:edges){
        int u=x[0],q=x[1];
        v[u].push_back(q);
        v[q].push_back(u);
    }
 queue<int>qu;
    qu.push(0);
    vector<bool>vis(n+1);
    vis[0]=1;
    int q=0;
    while(!qu.empty())
    {
        int sz=qu.size();
        while(sz--)
        {
            int me=qu.front();
            qu.pop();
            for(auto & j:v[me])
            {
                if(!vis[j])
                {
                    vis[j]=1;
                    qu.push(j);
                    dis[0]+=q+1;
                }
            }
        }
        q++;
    }

    
  dfs1(0,0);
 dfs2(0,0);
return dis;



    }
};