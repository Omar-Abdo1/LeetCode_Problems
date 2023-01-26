class Solution {
public:
    
int dp[31][31];
    vector<vector<int>> generate(int numRows) {
    int n=numRows;
     dp[0][0]=1;
     for(int row=0;row<n;++row){
         for(int col=0;col<=row;++col){
           dp[row+1][col]+=dp[row][col];
           dp[row+1][col+1]+=dp[row][col];  
         }
     } 
     vector<vector<int>>v;
     for(int i=0;i<n;++i){
         vector<int>t;
         for(int j=0;j<=i;++j){
             t.push_back(dp[i][j]);
         }
         v.push_back(t);
     }
     return v;

        
    }
};