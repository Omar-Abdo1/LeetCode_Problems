class Solution {
public:
    int countSubstrings(string s) {
        function<bool(int,int)> check=[&](int l,int r)->bool{
           while(l>=0 && r<s.size() && s[l]==s[r])
            ++l , --r;
            return r<l;
        };
        int ans = 0;
        for(int i=0;i<s.size();++i){
            for(int j=i;j<s.size();++j)
           ans+=check(i,j);
        }
        return ans;
    }
};