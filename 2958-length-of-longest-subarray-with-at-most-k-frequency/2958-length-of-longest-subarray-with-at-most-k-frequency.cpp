class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

      int ans = 0,n=nums.size();
      unordered_map<int,int>mp;
      for(int r=0,l=0;r<n;++r){
         ++mp[nums[r]];
         
            while(l<=r && mp[nums[r]]>k)
            --mp[nums[l++]];
          
         ans = max(ans,r-l+1);
      }
       return ans;
    }
    /*
     
     k = 2

     1 2 3 3 3 6 

    */
};