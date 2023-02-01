class Solution {
public:
    bool can(string &s, string &t, string &pre){
   
    for(int i=0;i<s.size();i+=pre.size()){
    string me=s.substr(i,pre.size());
    if(me!=pre)return 0;
    }    
    
    for(int i=0;i<t.size();i+=pre.size()){
    string me=t.substr(i,pre.size());
    if(me!=pre)return 0;
    }    
        return 1;
        
        
    }
    string gcdOfStrings(string s, string t) {
     int sz=__gcd(s.size(),t.size());
     string me=s.substr(0,sz);
     if(can(s,t,me))return me;
        else return "";
    }
};