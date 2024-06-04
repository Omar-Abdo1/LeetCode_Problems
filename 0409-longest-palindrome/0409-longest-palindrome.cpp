class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>f(26 * 2);
            
        for(auto &ch : s)
        {
             if(islower(ch))
                 ++f[ch-'a'];
            else ++f[ch-'A' + 26];
        }
        int ans = 0;
        for(int i=0;i<26*2;++i)
        {
            ans+= (f[i]/2 ) * 2;
            f[i]%=2;
        }
        for(int i=0;i<26*2;++i)
            if(f[i]){
                ++ans; break;
            }
        return ans;
    }
};