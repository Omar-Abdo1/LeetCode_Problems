#define dd double
class Solution {
public:
    
    int maxPoints(vector<vector<int>>& v) {
        int n=v.size();
        int mx=min(2,n);
      for(int i=0;i<n;++i){
          for(int j=0;j<n;++j){
              if(i==j)continue; 
           dd x1=v[i][0];
            dd y1=v[i][1];
              dd x2=v[j][0];
              dd y2=v[j][1];
              int cnt=2;
              for(int k=0;k<n;++k){
                if(k==i || k==j)continue;
                  dd x3=v[k][0];
                  dd y3=v[k][1];
               double a= x1*(y2-y3) - y1*(x2-x3) + (x2*y3 - y2*x3);
                cnt+=!a;  
              }
              mx=max(mx,cnt);
              
              
              
          }
      }
        return mx;
    }
};