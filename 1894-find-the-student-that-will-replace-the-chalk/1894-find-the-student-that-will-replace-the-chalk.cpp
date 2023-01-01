class Solution {
public:
    int chalkReplacer(vector<int>& v, int k) {
     long long sum=0;
        for(auto &i:v)sum+=i;
        k%=sum;
        for(int i=0;i<v.size();++i){
            if(k-v[i]>=0){
                k-=v[i];
            }
            else{
                return i;
            }
        }
        return 0;
    }
};