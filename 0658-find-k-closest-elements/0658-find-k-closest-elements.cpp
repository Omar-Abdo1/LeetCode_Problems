class Solution {
public:
    vector<int> findClosestElements(vector<int>& v, int k, int x) {
      vector<pair<int,int>>vp;
        for(auto i : v){
            vp.push_back({abs(i-x),i});
        }
        vector<int>ans;
        sort(vp.begin(),vp.end());
        for(int i=0;i<k;++i)
            ans.push_back(vp[i].second);
                sort(ans.begin(),ans.end());

        return ans;
        
    }
};