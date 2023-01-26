class Solution {
public:
    int dp[35][35];
    vector<int> getRow(int rowIndex) {    
    int n=rowIndex;
     dp[0][0]=1;
     for(int row=0;row<n;++row){
         for(int col=0;col<=row;++col){
           dp[row+1][col]+=dp[row][col];
           dp[row+1][col+1]+=dp[row][col];  
         }
     } 
       vector<int>t;
        for(int j=0;j<=n;++j){
            t.push_back(dp[n][j]);
        }
        return t;

        
    
    }
};