class Solution {
public:
    bool getBit(int n,int idx){
        return (n>>idx)&1;
    }
    vector<int> singleNumber(vector<int>& v) {
      
        /*
         if we take xor for all array we will have 
         x^y  
         
         then we will see the first bit that diffrent and make them two groubs
         groub1 : bit the is on
         groub2 : bit the is off 
         then get xor in groub1 to get x and get y from second
        */
        
        vector<int>ans(2);
        int Xor  = 0;
        for(auto &i:v)
            Xor^=i;
        int bit = 0;
        for(int i=0;i<32;++i)
            if(getBit(Xor,i)){
                bit = i;
                break;
            }
        
        for(auto &num : v)
        {
             if(getBit(num,bit))
                 ans[0]^=num;
            else ans[1]^=num;
        }
        return ans;
        
    }
};