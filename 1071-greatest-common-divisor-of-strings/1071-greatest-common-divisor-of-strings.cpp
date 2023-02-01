class Solution {
public:
    bool can(string &s, string &t, string &pre){
    if(s.size()%pre.size() || t.size()%pre.size())return 0;
   
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
    string q;
    string pre;
      if(s.size()<t.size())swap(s,t);
     for(int i=0;i<t.size();++i){
         q+=s[i];
         if(can(s,t,q))pre=q;
     }
        return pre;
    }
};