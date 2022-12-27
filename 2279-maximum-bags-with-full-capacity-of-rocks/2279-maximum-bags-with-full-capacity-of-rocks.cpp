class Solution {
public:
    struct oo {
        int x,y,c;
        bool operator < (const oo&e)const{
            return c<e.c;
        }
    };
    int maximumBags(vector<int>& c, vector<int>& r, int k) {
        vector<oo>v;
        for(int i=0;i<c.size();++i)v.push_back({r[i],c[i],c[i]-r[i]});
        int ans=0;
        sort(v.begin(),v.end());
     for(auto &[x,y,z] : v){
         if(k>=z){
             k-=z;
             ans++;
         }
     }
     return ans;
     
    }
};