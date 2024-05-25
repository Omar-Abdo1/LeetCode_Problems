class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
      vector<string>ans;
        set<string>st;
        for(auto &i : wordDict)
            st.insert(i);
        string t = "";
        char sp =' ';
        function<void(int)>rec=[&](int idx){
            if(idx==s.size())
                ans.push_back(t.substr(0,t.size()-1));
            
            string cur;
            for(int i = idx ; i<s.size();++i){
                cur.push_back(s[i]);
                if(st.count(cur)){
                    for(auto &ch : cur)
                        t.push_back(ch);
                    t.push_back(sp);
                    rec(i+1);
                    t.pop_back();
                    string temp = cur;
                    while(temp.size() && t.back()==temp.back())
                        temp.pop_back(),t.pop_back();
                }
            }
        };
        rec(0);
        return ans;
    }
};