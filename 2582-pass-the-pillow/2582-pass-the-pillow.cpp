class Solution {
public:
    int passThePillow(int n, int time) {
        time%=(2* (n-1) );
        for(int i=1;i<=n;++i){
            if(!time--){
                return i;
            }
        }
        for(int i=n-1;i>=1;--i){
            if(!time--){
                return i;
            }
        }
        return -1;
    }
};