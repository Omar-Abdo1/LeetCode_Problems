class Solution {
public:
    int maxDistance(vector<int>& v, int m) {
     sort(v.begin(),v.end());
      function<bool(int)>can=[&](int mid){
         int rem = m-1;
          int prv = v[0];
          for(int i=1;i<v.size();++i){
              if(v[i]-prv>=mid){
                  --rem;
                  prv  =v[i];
              }
          }
          return rem<=0;
      };
      
        int l = 0,r=v.back(),mid,ans=-1;
        while(l<=r){
            mid = l+r>>1;
            can(mid) ? ans=mid,l=mid+1 : r=mid-1;
        }
        return ans;
    }
};