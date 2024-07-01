class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
       int ans = 0;
       long long sum = 0;
        int i =0;
        while(sum<n){
             if(i<nums.size() && nums[i]-sum<=1 ) {
                 sum += nums[i++];
             }
            else{
                // if my sum is 3   then i have covers [0,1,2,3] so i need to put 4
                sum += (sum+1);
                ++ans;
            }
        }
        return ans;
        
    }
};
/*

0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

1 1 0 0 0 1 1 0 0 0 1 1 0 0   0  0  0  1  0  0  0  0

*/