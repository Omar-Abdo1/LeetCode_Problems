class Solution {
public:
    vector<vector<int>> subsets(vector<int>& v) {
        int n = v.size();
        vector<vector<int>>ans(1<<n);
        for(int i=0;i<1<<n;++i){
             for(int j=0;j<n;++j)
                 if((i>>j)&1)
                     ans[i].push_back(v[j]);
                     
        }
        return ans;
    }
};