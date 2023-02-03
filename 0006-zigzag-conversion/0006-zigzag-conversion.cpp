class Solution {
public:
    string convert(string s, int nr) {
        char grid[nr+2][s.size()/2 + 5];
        if(nr==1)return s;
     
        memset(grid,'0',sizeof grid);
       int i=0;
       int r=1,c=1;
        int n=nr;
        int m=(s.size()+1)/2 ;
       while(i<s.size()){
        // get down
        while( i<s.size() && r<=n){
            grid[r][c]=s[i];
            ++i;
            ++r;
        }
        // diagonal up
         r-=2; ++c;
        while( i<s.size() && r>1 && c<=m){
            grid[r][c]=s[i];
            r--;
            ++c;
            ++i;
        }
       }
        string me;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(grid[i][j]!='0')me+=grid[i][j];
            }
        }

        return me;
    }
};