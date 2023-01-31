class Solution {
public:
int n;
vector<pair<int,int>>v;
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
      n=ages.size();
    v.push_back({0,0});
    for(int i=0;i<n;++i)
    v.push_back({ages[i],scores[i]});
     sort(v.begin(),v.end());
    int dp[1007][1007]={0};
//dp[i][lst] the max score when lst the last indx taken
//and i is the current indx

for(int i=n;i>=0;--i){
  for(int lst=0;lst<=n;++lst){
   dp[i][lst]=dp[i+1][lst];
   if(v[i].first>v[lst].first && v[i].second>=v[lst].second){
    dp[i][lst]=max(dp[i][lst],v[i].second+dp[i+1][i]);
   }
   else if(v[i].first==v[lst].first){
    dp[i][lst]=max(dp[i][lst],v[i].second+dp[i+1][i]);
   }
  }
}
        return dp[0][0];


        
    }
};