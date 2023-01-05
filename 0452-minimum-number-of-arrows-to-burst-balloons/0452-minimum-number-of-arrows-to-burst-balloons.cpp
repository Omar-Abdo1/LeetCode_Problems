class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& q) {
        vector<pair<int,int>>v;
        for(auto &x:q)v.push_back({x[0],x[1]});
        sort(v.begin(),v.end());
        /*
        1 6 -->(2,6)
        2 8 ->>(7,6)
        7 12
        10 16
        */
        int l=v[0].first,r=v[0].second;
        int cnt=1;
        for(int i=1;i<v.size();++i){ 
            auto [l1,r1]=v[i];
            int newL=max(l1,l);
            int newR=min(r1,r);
            if(newL>newR){
                ++cnt;
                l=l1;
                r=r1;
                continue;
            }
            l=newL;
            r=newR;
        }
        return cnt;
        
    }
};