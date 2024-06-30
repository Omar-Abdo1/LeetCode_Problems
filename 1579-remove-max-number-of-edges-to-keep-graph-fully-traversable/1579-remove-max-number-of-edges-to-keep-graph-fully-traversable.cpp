class DSU
     {
    #define ll long long 

            public : 
     
         vector<int>par;
         vector<ll>sz;
     
         DSU(int n)
         {
             par=vector<int>(n+1);
             sz=vector<ll>(n+1,1);
             iota(par.begin(),par.end(),0);
         }
     
         int find(int i)
         {
             if(i==par[i])
                 return i;
             return par[i]=find(par[i]);
         }
     
         void mergeSet(int i,int j)
         {
     
             int a = find(i);
             int b =find(j);
             if(a!=b)
             {
                 if(sz[a]<sz[b])
                     swap(a,b);
                 par[b]=a;
                 sz[a]+=sz[b];
             }
         }
     
         bool sameSet(int i,int j)
         {
             return find(i)==find(j);
         }
     
     
     };
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),[&](auto v1,auto v2){
           return v1[0]>v2[0]; 
        });
        int tr=0;
        DSU d1(n+1),d2(n+1);
        int ans = 0;
        for(auto &v : edges){
            if(v[0]==3 &&  (!d1.sameSet(v[1],v[2]) || !d2.sameSet(v[2],v[1]))){
                d1.mergeSet(v[1],v[2]);
                d2.mergeSet(v[1],v[2]);
            }
            else if(v[0]==3){
                ++ans;
            }
            else if(v[0]==2){
             d2.sameSet(v[1],v[2]) ? ++ans : tr++,d2.mergeSet(v[1],v[2]);
            }
            else{
            d1.sameSet(v[1],v[2]) ? ++ans : tr++,d1.mergeSet(v[1],v[2]);
            }
        }
    for(int i=1;i<=n;++i){
        if(!d1.sameSet(i,1) || !d2.sameSet(i,1))return -1;
    }
    return ans;
    }
};