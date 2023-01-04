class Solution {
public:
    int minimumRounds(vector<int>& v) {
          
        int ans=0;
priority_queue<pair<int,int>>pq;
map<int,int>mp;
for(auto &i :v)mp[i]++;
        
for(auto &[x,y] :mp){
    pq.push({x,y});
}
        
while(!pq.empty()){
    ++ans;
    auto [x,y]=pq.top();
    pq.pop();
    if(y==1)return -1;
    if(y%2==0){
        y%3 ? y-=2 : y-=3 ;
    }
    else{
        y-=3;
    }
    if(y)pq.push({x,y});

}
return ans;

    }
};