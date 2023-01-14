class Solution {
public:
    bool can(int mid , vector<int>&v,int m, int k){
        int ans=0;
       vector<int>t(v.size());
        for(int i=0;i<t.size();++i)
            if(v[i]<=mid)t[i]=1;
        // k consective flowers 
        int i=0;
        while(i<v.size()){
          
            if(t[i]){
                int j=i;
                while(j<v.size() && t[j]) ++j;
                ans+= (j-i)/k;
                i=j;
            }
            ++i;
        }
         
        
       return ans>=m;
    }
    int minDays(vector<int>& v, int m, int k) {
              
        int l=1,r=1e9,mid,ans=-1;
        while(l<=r){
            mid=(l+r)/2;
            can(mid,v,m,k) ? r=mid-1,ans=mid  : l=mid+1;
        }
        return ans;
        
    }
};