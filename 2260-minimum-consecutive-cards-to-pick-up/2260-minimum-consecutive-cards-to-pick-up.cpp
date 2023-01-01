class Solution {
public:
    const int N=1e6+1;
    int mp[1000007];
    bool can(int mid,vector<int>&v){
         memset(mp,0,sizeof mp);
        int p=0;
     for(int i=0;i<mid;++i){
         mp[v[i]]++;
         if(mp[v[i]]==2)p++;
     }
     for(int i=mid,j=0;i<v.size();++i && j++){
         if(p>=1)return 1;
         mp[v[j]]--;
         if(mp[v[j]]==1)p--;
         mp[v[i]]++;
         if(mp[v[i]]==2)p++;
     }
        return p>=1;
        
    }
    int minimumCardPickup(vector<int>& v) {
      
        int l=1,r=v.size(),mid,ans=-1;
        while(l<=r){
            mid=(l+r)/2;
            can(mid,v) ? r=mid-1,ans=mid :l=mid+1; 
        }
        return ans;
         
        
        
    }
};