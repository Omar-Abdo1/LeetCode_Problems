class Solution {
public:
    int minMovesToSeat(vector<int>& v, vector<int>& vv) {
        int ans = 0 ;
        sort(v.begin(),v.end());
        sort(vv.begin(),vv.end());
        for(int i=0;i<v.size();++i)ans+=abs(v[i]-vv[i]);
        return ans;
    }
};