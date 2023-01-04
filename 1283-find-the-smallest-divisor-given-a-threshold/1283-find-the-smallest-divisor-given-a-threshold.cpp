class Solution {
public:
    bool can(int mid,vector<int>&v,int &k){
      long long sum=0;
        for(int i=0;i<v.size();++i){
            sum+=(v[i]+mid-1)/mid;
        }
        return sum<=k;
    }
    int smallestDivisor(vector<int>& v, int k) {
        long long l=1,r=1e18,mid;
        while(l<=r){
            mid=(l+r)/2;
            can(mid,v,k)?r=mid-1:l=mid+1;
        }
        return ++r;
    }
};