class Solution {
public:
    struct oo{
        long long st,take,i;
      bool operator < (const oo&e) const {
            if(st!=e.st) return st<e.st;
            else if(take!=e.take)return take<e.take;
            return i<e.i;
        }
    };
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<oo>v;
        vector<int>ans;
        int i=0;
        for(auto &x : tasks )v.push_back({x[0],x[1],i++});
        sort(v.begin(),v.end());    
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
           long long time=0;
            i=0;
           while(i<v.size()){
          
           while(i<v.size() && time>=v[i].st){
                pq.push({v[i].take,v[i].i});
                i++;
            }
            if(pq.empty()){
               pq.push({v[i].take,v[i].i});
               time=v[i].st;
               i++;
            }
            auto [x,y]=pq.top();
            pq.pop();
            ans.push_back(y);
            time+=x;
           }
        
           while(!pq.empty()){
                  auto [x,y]=pq.top();
            pq.pop();
            ans.push_back(y);
           }
           
    
       return ans;
    }
};