class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        
        function<bool(string)>pal=[&](string t){
            string tt = t;
            reverse(tt.begin(),tt.end());
            return tt==t;
        };
        
        function<void(int)>rec=[&](int idx){
            
            if(idx==s.size()){
                ans.push_back(temp);
                return;
            }
            
            string t;
            for(int i=idx;i<s.size();++i){
                t.push_back(s[i]);
                if(pal(t))
                {
                    temp.push_back(t);
                    rec(i+1);
                    temp.pop_back();
                }
            }
        };
        rec(0);
        return ans;
    }
};