class Solution {
public:
   
    int minSubArrayLen(int target, vector<int>& v) {
        
       int l=1,r=v.size();
        while(l<=r){
            int mid=(l+r)/2;
      long long sum=0;
            bool ok=0;
    for(int i=0;i<mid;++i)sum+=v[i];
      if(sum>=target){
       ok=1;
      }
        for(int i=mid;i<v.size();++i){
            sum+=v[i]-v[i-mid];
            if(sum>=target)ok=1;
        }
ok ? r=mid-1 : l=mid+1;        
        
        
        }
++r;
        return r>v.size() ? 0 : r;
        
        
        
    }
  
    
    
};