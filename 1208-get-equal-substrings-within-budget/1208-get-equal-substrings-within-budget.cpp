class Solution {
public:
    int equalSubstring(string s, string t, int k) {
        vector<int>pre(s.size());
        for(int i=0;i<s.size();++i){
            pre[i] = abs(s[i]-t[i]);
            if(i)
                pre[i]+=pre[i-1];
        }
        int mx = 0;
        for(int i=0;i<s.size();++i){
            int l=i,r=s.size()-1,mid,ans=-1;
            while(l<=r){
                mid = l+r>>1;
                int cost = pre[mid];
                if(i)cost-=pre[i-1];
             cost<=k ? ans=mid,l=mid+1 : r=mid-1;   
            }
            if(~ans)
            mx=max(mx,ans-i+1);
        }
        return mx;
    }
};