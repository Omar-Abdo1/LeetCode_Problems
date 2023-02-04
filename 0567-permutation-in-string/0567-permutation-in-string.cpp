class Solution {
public:
    int f[32];
    int me[32];
    bool can(){
       for(int i=0;i<26;++i)
           if(me[i]!=f[i])return 0;
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
      int k=min(s1.size(),s2.size());
       for(auto &i:s1)++f[i-'a'];
        
      for(int i=0;i<k;++i){
         ++me[s2[i]-'a'];
      }
      if(can())return 1;
        for(int i=k;i<s2.size();++i){
            --me[s2[i-k]-'a'];
            ++me[s2[i]-'a'];
            if(can())return 1;
        }
        return can();
        
        
    }
};