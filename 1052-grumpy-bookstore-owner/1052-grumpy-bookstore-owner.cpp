class Solution {
public:
    int maxSatisfied(vector<int>& v, vector<int>& t, int k) {
        vector<int>pre(v.size());
        vector<int>pre2(v.size());
        for(int i=0;i<v.size();++i)
        {
            pre[i]=v[i];
            if(!t[i])
                pre2[i]=v[i];
            if(i)
                pre[i]+=pre[i-1] , pre2[i]+=pre2[i-1];
        }
        int tot = 0;
        for(int i=0;i<v.size();++i)
            if(!t[i])
                tot+=v[i];
        int ans = 0;
        for(int i=0;i+k-1<v.size();++i){
            int l = i,r=i+k-1;
            int gain = pre[r] - (l==0 ? 0 : pre[l-1]);
            int _gain = pre2[r] - (l==0 ? 0 : pre2[l-1]);
            ans = max(ans, tot + gain - _gain );
        }
        return ans;
    }
};