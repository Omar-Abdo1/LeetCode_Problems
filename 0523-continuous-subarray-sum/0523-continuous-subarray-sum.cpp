class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum = 0;
        mp[sum] = -1;
        for(int i=0;i<(int)nums.size();++i){
            sum += nums[i];
            sum%=k;
            if(mp.count(sum)){
                int l = mp[sum] + 1;
                int r = i;
                if(r-l+1>=2)return 1;
            }
            if(mp.count(sum)==0)
                mp[sum] = i;
        }
        return 0;
    }
};

/*
 pre[r] - pre[l-1]
 pre[r]%k = pre[l-1]%k
 
 r = i   
 
 
 23 2 4 6 7
 5  1 5 5 0 
  
*/