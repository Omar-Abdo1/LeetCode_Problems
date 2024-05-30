class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int>pre(n);
        for(int i=0;i<n;++i){
            pre[i] = arr[i];
            if(i)
                pre[i]^=pre[i-1];
        }
        function<int(int,int)>get=[&](int l,int r)->int{
            if(l==0)return pre[r];
            else return pre[r]^pre[l-1];
        };
        int ans = 0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                 for(int k=j;k<n;++k){
                     if(get(i,j-1)==get(j,k))++ans;
                 }
            }
        }
        return ans;
        
    }
};