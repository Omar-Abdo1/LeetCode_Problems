class Solution {
public:
    int furthestBuilding(vector<int>& v, int b, int k) {
        priority_queue<int>pq;
        int i=0;
        for(;i+1<v.size();++i){
            int cur = v[i];
            int nxt = v[i+1];
            int diff = nxt - cur;
            if(diff<=0)continue;
            b-=diff;
            pq.push(diff);
            while(k>0 && b<0){
                 b += pq.top();
                 pq.pop();
                 --k;
            }
            if(b<0)break;
        }
        return i;
    }
};