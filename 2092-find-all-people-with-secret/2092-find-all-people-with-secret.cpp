class DSU
  {
      using ll = long long;
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
              if(a>b)
                  swap(a,b);
              par[b]=a;
              sz[a]+=sz[b];
          }
      }

      void Reset(int i,int j){
          par[i] = i;
          par[j] = j;
          sz[i] = 1;
          sz[j] = 1;
      }
  
      bool sameSet(int i,int j)
      {
          return find(i)==find(j);
      }
  
  
  };
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        map<int,vector<pair<int,int>>>mp;
        vector<int>ans;
        for(auto &v : meetings){
            mp[v[2]].push_back({v[0],v[1]});
        }
        DSU dsu(n+1);
        dsu.mergeSet(0,firstPerson);
        for(auto &[t,v] : mp){
              
               for(auto &[x,y] : v){
                   dsu.mergeSet(x,y);
               }

               for(auto &[x,y] : v){
                   if(!dsu.sameSet(x,0)){
                       dsu.Reset(x,y);
                   }
               }

        }
         
         for(int i=0;i<n;++i)
         if(!dsu.find(i))ans.push_back(i);

      return ans;
    }
};