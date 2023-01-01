class Solution {
public:
            int mp[1000007];

    int minimumCardPickup(vector<int>& v) {
      int ans=1e9;
      for(int i=0;i<v.size();++i){
          if(mp[v[i]]){
              ans=min(ans,i-mp[v[i]]+2);
          }
          mp[v[i]]=i+1;
      }
        if(ans==1e9)ans=-1;
        return ans;
        
        
    }
};