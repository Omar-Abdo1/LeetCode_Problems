class Solution {
public:
    
    vector<int> answerQueries(vector<int>& v, vector<int>& queries) {
    vector<int>ans;
    sort(v.begin(),v.end());
     for(int i=1;i<v.size();++i)v[i]+=v[i-1];
        for(auto &i :queries){
            auto it=upper_bound(v.begin(),v.end(),i)-v.begin();
            ans.push_back(it);
        }
        return ans;
    }
};