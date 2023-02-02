class Solution {
public:
    int wiggleMaxLength(vector<int>& v) {
        int n=v.size();
       vector<int>pos(n+1),neg(n+1);
       pos[0]=neg[0]=1;
       for(int i=1;i<n;++i){
           if(v[i]>v[i-1]){
               pos[i]=neg[i-1]+1;
           }
           else if(v[i]<v[i-1]){
               neg[i]=pos[i-1]+1;
           }
               pos[i]=max(pos[i-1],pos[i]);
               neg[i]=max(neg[i-1],neg[i]);
       }
       return max(pos[n-1],neg[n-1]);
       
    }
};