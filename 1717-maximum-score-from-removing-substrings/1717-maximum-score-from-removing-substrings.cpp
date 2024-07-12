class Solution {
public:
    int maximumGain(string s, int x, int y) {
     
        string rm1="ab",rm2="ba";
        if(x<y)
            swap(rm1,rm2) , swap(x,y);
        
        function<int(string,int)>go=[&](string rm,int gain){
        bool ok = 1;
        int ans = 0;
        while(ok){
            ok = 0;
            for(int j=0;j+1<s.size();++j){
                if(s[j]==rm[0] && s[j+1]==rm[1])
                {
                    s[j]=s[j+1]='X';
                    ans+=gain;
                    int ii = j-1,jj=j+2;
                    ok=1;
                    while(ii>0 && jj<s.size() && s[ii]==rm[0] && s[jj]==rm[1] ){
                        s[ii]=s[jj]='X'; 
                        --ii;
                        ++jj;
                        ans+=gain;
                    }
                    j=jj-1;
                }
            }
            s.erase(remove(s.begin(), s.end(), 'X'), s.end());
        }
            return ans;
    };
        int ans =0 ;
        ans+=go(rm1,x);
        ans+=go(rm2,y);
        return ans;
        
        
    }
};
/*
3y
x
cdbc


aaxybb

"aaxybbaabb"



*/