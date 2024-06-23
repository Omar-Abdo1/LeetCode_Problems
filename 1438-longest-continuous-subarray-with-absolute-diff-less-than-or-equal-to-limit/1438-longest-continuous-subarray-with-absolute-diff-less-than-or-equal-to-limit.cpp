class Solution {
public:
    int longestSubarray(vector<int>& v, int k) {
                
        function<int(int)>can=[&](int mid){
            multiset<int>st; 
            for(int i=0;i<mid;++i)
                st.insert(v[i]);
                int f = *st.begin();
                int s = *st.rbegin();
             if(s-f<=k)
                 return 1;
            for(int i = mid;i<v.size();++i){
               st.erase(st.find(v[i-mid]));
                st.insert(v[i]);
                 int f = *st.begin();
                int s = *st.rbegin();
             if(s-f<=k)
                 return 1;
            }
            return 0;
        };
       
       int l = 1,r=v.size(),mid,ans=0;
        while(l<=r){
            mid = l+r>>1;
            can(mid) ? ans=mid,l=mid+1 : r=mid-1;
        }
        return ans;
    }
};
/*

*/