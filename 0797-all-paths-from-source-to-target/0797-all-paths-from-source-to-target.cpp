class Solution {
public:
vector<vector<int>>ans;
vector<int>t;
   void dfs(int i,vector<vector<int>>&v){
      t.push_back(i);
      if(i==v.size()-1){
        ans.push_back(t);
          return ;
      }
      for(auto &j :v[i]){
            dfs(j,v);
            t.pop_back();
      }

    }  

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& v) {
        dfs(0,v);
        return ans;
    }
};