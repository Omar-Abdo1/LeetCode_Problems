class Solution {
public:
    int max(int i, int j){
        return  i>=j ? i : j;
    }
    int min(int i, int j){
        return i>=j ? j:i;
    }
    int maxSubArray(vector<int>& v) {
        int n=v.size();
        vector<long long>pre(n+1);
        pre[0]=v[0];
        for(int i=1;i<n;++i)pre[i]+=pre[i-1]+v[i];
        int mx=pre[0];
        int mn=0;
        for(int i=0;i<n;++i){
            mx=max(mx,pre[i]-mn);
            mn=min(mn,pre[i]);
        }
        return mx;
        
    }
};