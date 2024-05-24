class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        vector<int>f(26);
        for(auto &ch : letters)++f[ch-'a'];
        int ans = 0;
        for(int msk=1;msk<1<<n;++msk){
            vector<int>t = f;
            vector<string>v;
            for(int i=0;i<n;++i)
                if((msk>>i)&1)
                    v.push_back(words[i]);
             bool ok = 1;
            int sum=0;
            for(auto &s : v){
                for(auto &ch : s){
                    if(t[ch-'a']==0){
                        ok=0;
                        break;
                    }
                    sum+=score[ch-'a'];
                    --t[ch-'a'];
                }
            }
            if(ok)
                ans=max(ans,sum);
        }
        return ans;
    }
};