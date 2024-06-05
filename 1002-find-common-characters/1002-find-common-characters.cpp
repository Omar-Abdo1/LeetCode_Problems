class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<vector<int>>f(26,vector<int>(n));
        for(char ch = 'a';ch<='z';++ch){
             for(int i=0;i<n;++i){   
                   for(auto &j : words[i])
                    if(j==ch)
                        ++f[ch-'a'][i];
             }
        }
        
        function<int(char)>get=[&](char ch){
            int mn = 1e9; 
            for(int i=0;i<n;++i)
                mn=min(mn,f[ch-'a'][i]);
            return mn;
        };
        vector<string>ans;
        for(char ch ='a' ; ch<='z' ;++ch){
            int freq = get(ch);
            string t; t.push_back(ch);
            while(freq--)
                ans.push_back(t);
        }
        return ans;
    }
};