class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>in(n);
        for(auto &v : roads){
            ++in[v[0]];
            ++in[v[1]];
        }
        vector<int>v(n);
        iota(v.begin(),v.end(),0);
        sort(v.begin(),v.end(),[&](int x,int y){
           return in[x]>in[y]; 
        });
        vector<int>val(n);
        for(int i=0;i<n;++i)
            val[v[i]] = n-i;
        long long ans = 0;
        for(auto &e : roads){
            ans += val[e[0]] + val[e[1]];
        }
        return ans;
    }
};