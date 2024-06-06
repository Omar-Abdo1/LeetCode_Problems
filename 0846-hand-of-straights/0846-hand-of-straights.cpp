class Solution {
public:
    bool isNStraightHand(vector<int>& v, int k) {
        map<int,int>mp;
        int n = v.size();
        sort(v.begin(),v.end());
        for(auto &i : v)++mp[i];
        
        if(n%k)
            return 0;
        int sz = n/k;
        while(!mp.empty()){
            int cur = mp.begin()->first;
            for(int i=0;i<k;++i){
                if(mp[cur+i]==0) return 0;
                if(--mp[cur+i]==0)mp.erase(cur+i);
            }
    
        }
        return 1;
    }
};