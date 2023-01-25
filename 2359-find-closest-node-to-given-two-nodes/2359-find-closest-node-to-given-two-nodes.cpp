class Solution {
public:
    void bfs(int s,vector<int>&dist,vector<vector<int>>&v){
      dist[s]=0;
        queue<int>qu;
            qu.push(s);
        while(!qu.empty()){
          auto cur=qu.front();
            qu.pop();
            for(auto &j :v[cur]){
                if(dist[j]==-1){
                    dist[j]=dist[cur]+1;
                    qu.push(j);
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int>>v(n+1);
        vector<int>dist1(n+1,-1),dist2(n+1,-1);
        for(int i=0;i<n;++i){
            if(~edges[i])
             v[i].push_back(edges[i]); 
        }
        bfs(node1,dist1,v);
        bfs(node2,dist2,v);
        int ans=-1;
       int  mn=1e9;
        for(int i=0;i<n;++i){
            
        if(~dist1[i] && ~dist2[i] && max(dist1[i],dist2[i])<mn)
                ans=i,mn=max(dist1[i],dist2[i]);
          
        }
            return ans;
        
        
    }
};