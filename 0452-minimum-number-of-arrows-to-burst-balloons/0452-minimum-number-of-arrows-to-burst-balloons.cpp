class Solution {
public:
    int findMinArrowShots(vector<vector<int>>&v) {
        sort(v.begin(),v.end());
        int l=v[0][0],r=v[0][1];
        int cnt=1;
        for(int i=1;i<v.size();++i){ 
            int l1=v[i][0],r1=v[i][1];
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