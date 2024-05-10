class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        function<int(int)>solve=[&](int k){
        int ans = 0,n=nums.size(),dis=0;
        unordered_map<int,int>mp;
        for(int r=0,l=0;r<n;++r){
            ++mp[nums[r]];
            if(mp[nums[r]]==1)++dis;
             while(l<=r && dis>k){
                --mp[nums[l]];
                if(mp[nums[l]]==0)--dis;
                ++l;
             }
            ans+=(r-l+1);
        }
        return ans;
    };
    return solve(k)-solve(k-1);
    }
};