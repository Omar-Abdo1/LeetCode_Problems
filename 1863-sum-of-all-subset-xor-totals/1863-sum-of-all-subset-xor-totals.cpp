class Solution {
public:
    int subsetXORSum(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        for(int i=1;i<1<<n;++i){
            int sum = 0;
            for(int j=0;j<n;++j)
                if((i>>j)&1)
                    sum^=v[j];
            ans+=sum;
        }
        return ans;
    }
};