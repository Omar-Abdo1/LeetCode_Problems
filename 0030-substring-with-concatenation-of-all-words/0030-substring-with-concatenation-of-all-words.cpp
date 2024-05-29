class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int tot = (int)words.size() * (int)words[0].size();
        int len = (int)words[0].size();
        unordered_map<string,int>mp;
        vector<int>ans;
        for(auto &i : words)++mp[i];
        
         for(int st=0;st<=(int)s.size()-tot;++st){
            
             auto mp2 = mp;
             string t = s.substr(st,tot);
             bool ok = 1;
             for(int j=0;j<tot;j+=len){
                 string tt = t.substr(j,len);
                 if(mp2[tt]){
                     --mp2[tt];
                 }
                 else {
                     ok = 0;
                     break;
                 }
             }
             if(ok)
                 ans.push_back(st);
             
         }
        
        return ans;
    }
};