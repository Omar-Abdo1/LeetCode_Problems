class Solution {
public:
    string replaceWords(vector<string>& v, string s) {
        set<string>st;
        for(auto &i : v)st.insert(i);
        vector<string>temp;
        string t = "";
        s = s + ' ';
        string ans = "";
        for(auto &ch : s){
            if(ch==' '){
                temp.push_back(t);
                t="";
            }
            else
            t.push_back(ch);
        }
        for(auto &i : temp){
            t = "";
            bool ok = 1;
            for(auto &ch : i){
                t.push_back(ch);
                if(st.count(t)){
                    for(auto &c : t)ans.push_back(c);
                    ans.push_back(' ');
                    ok  = 0;
                    break;
                }
            }
            if(ok){
                for(auto &c : t)ans.push_back(c);
                                 ans.push_back(' ');
            }
                
        }
        ans.pop_back();
        return ans;
    }
};