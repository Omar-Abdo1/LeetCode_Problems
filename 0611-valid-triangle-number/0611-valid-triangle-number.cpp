class Solution {
public:
    int triangleNumber(vector<int>& v) {
        
     int n=v.size(),ans=0;
  sort(v.begin(),v.end());
     for(int i=0;i<n;++i){
      int x=v[i];
         for(int j=i+1;j<n;++j){
             int y=v[j];
                 int z=lower_bound(v.begin(),v.end(),x+y)-v.begin();
                 z--;
                 if(z>=j)ans+=z-j;
         }


     }
     return ans;
        
        
        
    }
};