class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        priority_queue<int>pq;
        vector<pair<double,int>>v;
        for(int i=0;i<q.size();++i)
            v.push_back({ (double)1.0*w[i]/q[i] , q[i]});
        sort(v.begin(),v.end());
        double ans = 1e18;
        double sum = 0;
        for(int i=0;i<q.size();++i){
             sum += v[i].second;
            pq.push(v[i].second);
            if(i>=k-1){
                ans = min(ans,sum*v[i].first);
                sum-=pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};

/*

 me -> 10  , 70
 ali -> 5 , 30
 
 total = 15 
 
 me -> 10/15 -> 2/3  
 ali -> 5/15 -> 1/3 
 
 2/3 / 1/3  ->  70 / x    then x = 35
 
 0 70/10 -> 7
 2 30/5 -> 6
 1 50/20 -> 2.5
 
 0,1 -> 7 * (30) = 210
 0,2 -> 7 * (15) = 105
 1,2 ->  6 * (25) = 150
 
 
*/