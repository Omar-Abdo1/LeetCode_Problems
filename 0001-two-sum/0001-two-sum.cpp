class Solution {
public:
    vector<int> twoSum(vector<int>& v, int k) {
        vector<pair<int,int>>ans;
        vector<int>me;
        for(int i=0;i<v.size();++i)ans.push_back({v[i],i});
        sort(ans.begin(),ans.end());
        int l=0,r=v.size()-1;
        while(l<r){
            long long sum=ans[l].first+ans[r].first;
            if(sum==k){
                me={ans[l].second,ans[r].second};
                break;
            }
            sum<k ? l++ : r--;
        }
    return me;
    }
};