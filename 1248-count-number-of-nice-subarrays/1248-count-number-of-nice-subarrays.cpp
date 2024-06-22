class Solution {
public:
    int numberOfSubarrays(vector<int>& v, int k) {
        vector<int>ones;
        ones.push_back(0);
        for(int i=0;i<v.size();++i)
            if(v[i]&1)
                ones.push_back(i+1);
        ones.push_back(v.size()+1);
        
        int ans = 0 ;
        for(int i=1;i+k-1<ones.size()-1;++i){
            int z1 = ones[i]-ones[i-1] ;
            int z2 = ones[i+k] - ones[i+k-1] ;
            ans += z1*z2 ;
        }
        return ans;
    }
};

/*

0 1 0 0 1 1 0 1 0 1
pre[r] - pre[l-1] = k 

k-pre[r] 
 
*/