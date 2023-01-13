class Solution {
public:
    vector<vector<int>>v;
    string s;
    int n;
    int mx;
     int dfs(int i, int p){
      int l1=0,l2=0;
      for(auto &j :v[i])if(j!=p){
         int len=dfs(j,i); // get the longest chain from j 
        if(s[i]!=s[j]){ // assume l1 > l2     l1 , l2 long left and right 
            if(l1<len)l2=l1,l1=len; // if len>l1 then update l1,l2
            else if(l2<len)l2=len; // update only l2 
        }
      }
         
      mx=max({mx,l1+l2+1}); // the best answer is left+right+1 
         
      return max(l1,l2)+1; // node i return the longest chain to node p
     }

    int longestPath(vector<int>& q, string t) {
        n=q.size();
        s=t;
        v=vector<vector<int>>(n);
        for(int i=1;i<n;++i){
            v[i].push_back(q[i]);
            v[q[i]].push_back(i);
        }
        auto get=dfs(0,0);
        return mx;     
        
    }
};