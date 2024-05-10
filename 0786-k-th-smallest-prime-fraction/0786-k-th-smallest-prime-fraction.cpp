class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<arr.size();++i)
         for(int j=i+1;j<arr.size();++j)
            v.push_back({arr[i],arr[j]});
        sort(v.begin(),v.end(),[&](pair<int,int>a,pair<int,int>b){
         return a.first*b.second < a.second * b.first; 
        });     
        --k; 
        return {v[k].first,v[k].second};
    }
};