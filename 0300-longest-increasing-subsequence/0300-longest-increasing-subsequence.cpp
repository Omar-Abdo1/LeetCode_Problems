class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        
// lis in nlogn
vector<int>res;
res.push_back(v[0]);
vector<int>ans(v.size());
ans[0]=1;
for(int i=1;i<v.size();++i){
    int it=lower_bound(res.begin(),res.end(),v[i])-res.begin();
   if(v[i]>res.back()){
    res.push_back(v[i]);
   }
   else{
    res[it]=v[i]; // swap
   }
   ans[i]=it+1;
}
    return *max_element(ans.begin(),ans.end());
        
        
        
        
    }
};