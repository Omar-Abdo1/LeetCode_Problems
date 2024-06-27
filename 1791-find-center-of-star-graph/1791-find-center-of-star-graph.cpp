class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int>f; 
        int n  = 0 ;
        for(auto &v:edges){
            ++f[v[0]];
            ++f[v[1]];
            n=max(n,v[0]);
            n=max(n,v[1]);
        }
        for(int i=1;i<=n;++i)
            if(f[i]==n-1)
                return i;
        return 0;
    }
};