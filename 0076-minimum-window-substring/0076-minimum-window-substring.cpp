class Solution {
public:
    string minWindow(string s, string t) {
        // min substring of s that have all char from t
        int mn=1e9,st;
        int freq_t[125]={0},freq_s[125]={0};
        for(auto &i : t)freq_t[i]++;
        int can_go=0;
        for(int i=0,l=0;i<s.size();++i){
          freq_s[s[i]]++;
            if(freq_s[s[i]]<=freq_t[s[i]])can_go++;
            
            if(can_go==t.size()){ // can take this substring contains all t
               
     while( freq_t[s[l]]<freq_s[s[l]] || freq_t[s[l]]==0 )
         // have more than in t or does not present in t
                    freq_s[s[l++]]--;
                
                int sz=i-l+1;
                if(mn>sz){
                    mn=sz;
                    st=l;
                }
            }
        }
      return mn==1e9 ? "" : s.substr(st,mn);
        
    }
};