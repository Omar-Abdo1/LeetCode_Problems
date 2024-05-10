class Solution {
public:
    long long countSubarrays(vector<int>& v, int k) {
        long long mx = *max_element(v.begin(),v.end()),ans=0,cnt=0;
        
        for(int r=0,l=0;r<v.size();++r){
            cnt+=v[r]==mx;
            while(cnt>=k){
                ans+=v.size()-r;
                cnt-=v[l++]==mx;
            }
        }
        return ans;
    }
};