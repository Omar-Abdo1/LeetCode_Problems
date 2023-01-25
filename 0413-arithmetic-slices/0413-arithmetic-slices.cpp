class Solution {
public:
    bool check (vector<int>&t){
     if(t.size()<3)return 0;
     int need=t[1]-t[0];
        for(int i=1;i<t.size()-1;++i){
            if( t[i+1]-t[i]!=need )return 0;
        }
        return 1;
        
    }
    int numberOfArithmeticSlices(vector<int>& v) {
        int cnt=0;
        int n=v.size();
        for(int i=0;i<n;++i){
            vector<int>t;
            for(int j=i;j<n;++j){
             t.push_back(v[j]);
                cnt+=check(t);
            }
        }
        return cnt;
    }
};