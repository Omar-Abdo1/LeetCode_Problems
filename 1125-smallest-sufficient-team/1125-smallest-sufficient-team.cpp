class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& v, vector<vector<string>>& arr) {
        int n = v.size();
        int m = arr.size();
        vector<vector<int>>dp(m,vector<int>(1<<n,-1));
        unordered_map<string,int>mp; int id = 0;
        for(auto &s : v)mp[s]=id++;
       function<int(int,int)>rec=[&](int idx,int msk)->int{
           if(1<<n==msk+1)
               return 0;
            if(idx==m)
                return 1e9;
           int &ret = dp[idx][msk];
           if(~ret)return ret;
           ret = rec(idx+1,msk);
           int cur_msk = 0; for(auto &s : arr[idx])cur_msk|=(1<<mp[s]);
           ret=min(ret,1+rec(idx+1,msk|cur_msk));
           return ret;
       };
           vector<int>ans;
           function<void(int,int)>build=[&](int idx,int msk)->void{
           if(1<<n==msk+1)
               return ;
            if(idx==m)
                return;
           int opt = rec(idx,msk);
          int cur_msk = 0; for(auto &s : arr[idx])cur_msk|=(1<<mp[s]);  
           if(opt == rec(idx+1,msk)){
               build(idx+1,msk);
           }
           else if(opt==1+rec(idx+1,msk|cur_msk)){
               ans.push_back(idx);
               build(idx+1,msk|cur_msk);
           }
       };
        build(0,0);
        return ans;
    }
};
/*

0 0 1 -> 1
0 1 0 -> 1
1 0 1 -> 1

*/