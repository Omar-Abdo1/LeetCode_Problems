class Solution {
public:
    int minKBitFlips(vector<int>&v, int k) {
        vector<int>pre(v.size()+1);
        int flip = 0;
        int ans = 0 ;
        for(int i=0;i<v.size();++i){
            
            if(i>=k){
                if(pre[i-k]) // if i have flipped at indx i-k then flip return to its                                     //  orginal value
                    flip^=1;
            }
            
            // v[i]=0 flip = 0  val = 0
            // v[i] =0 flip = 1 val = 1
            
            if(!(v[i]^flip)){
                if(i+k>v.size())
                    return -1;
                pre[i] = 1;
                flip^=1;
                ++ans;
            }   
        }
        return ans;
     }
};