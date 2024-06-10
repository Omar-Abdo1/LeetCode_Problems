class Solution {
public:
    int heightChecker(vector<int>& v) {
        auto vv = v;
        sort(vv.begin(),vv.end());
        int ans = 0;
        for(int i=0;i<(int)v.size();++i)ans+=v[i]!=vv[i];
        return ans;
    }
};