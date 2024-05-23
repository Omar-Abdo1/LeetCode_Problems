class Solution {
public:
    int beautifulSubsets(vector<int>& v, int k) {
        int n = v.size(),ans=0;
        unordered_map<int,int>mp;
        function<int(int)>rec=[&](int idx)->int{
            if(idx==n)
                return 1;
            int ret = 0;
            if(!mp[v[idx]-k] && !mp[v[idx]+k])
            {
                ++mp[v[idx]];
                ret+=rec(idx+1);
                --mp[v[idx]];
            }
            ret+=rec(idx+1);
            return ret;
        };
        return rec(0)-1;
        
    }
};
/*
k = 3

5  8
5  2

3-5

10 
4 
10 4 
5 
10 5 
4 5 
10 4 5 
7 
5 7 
2 
10 2 
4 2 
10 4 2 
7 2 
1 
10 1 
5 1 
10 5 1 
7 1 
5 7 1 
2 1 
10 2 1 
7 2 1 

*/