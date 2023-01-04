class Solution {
public:
    int minimumRounds(vector<int>& v) {
          
    int ans=0;
priority_queue<pair<int,int>>pq;
map<int,int>mp;
for(auto &i :v)mp[i]++;
 
        for(auto & [x,y] : mp){
           
            if(y==1)return -1;
            else if(y%3==0){
                ans+=y/3; 
            }
            else{
                ans+=(y/3)+1 ;
            }
        }    
        return ans;
    }
 /*       
7 ->> 11 11 111

8 ->> 111 111 11
*/
        
};