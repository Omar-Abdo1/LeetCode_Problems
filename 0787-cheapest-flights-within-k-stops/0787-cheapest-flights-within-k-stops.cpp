class Solution {
public:
    struct oo{
      int node,cost,rem;
    bool operator<(const oo& e)const {
		return e.cost<cost;
	}
};
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>>v(n+1);
       for(auto & x : flights){
           int i=x[0];
           int j=x[1];
           int z=x[2];
           v[i].push_back({j,z});
       } 
        
    priority_queue<oo>pq;
    pq.push({src,0,k+1});
        vector<vector<int>>dp(n+1,vector<int>(k+3,1e9));
        dp[src][k]=0;
        while(!pq.empty()){
         auto [cur,cost,rem]=pq.top();
         pq.pop();
         if(!rem)continue;
          for(auto &[j,z] :v[cur]){
              if(cost+z<dp[j][rem-1]){
                  dp[j][rem-1]=cost+z;
                  pq.push({j,dp[j][rem-1],rem-1});
              }
          }
        }
        int mn=1e9;
        for(int i=0;i<=k;++i)
        mn=min(mn,dp[dst][i]);
        
        if(mn==1e9)mn=-1;
        return mn;
       

    }
    
};