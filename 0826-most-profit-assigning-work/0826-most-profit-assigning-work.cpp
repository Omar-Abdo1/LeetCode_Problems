class Solution {
public:
int bs(int x, vector<pair<int,int>>&v){
int l=0,r=v.size()-1,mid,ans=-1;
while(l<=r){
    mid=(l+r)/2;
    if(x>=v[mid].first){
        l=mid+1;
        ans=mid;
    }
    else{
        r=mid-1;
    }
}
return ans;
}

    int maxProfitAssignment(vector<int>& diff, vector<int>& gain, vector<int>& me){
    vector<pair<int,int>>v;

    vector<int>mx(diff.size()+1);

     for(int i=0;i<diff.size();++i)
     v.push_back({diff[i],gain[i]});
     sort(v.begin(),v.end());
     mx[0]=v[0].second;
     for(int i=1;i<v.size();++i)
     mx[i]=max(mx[i-1],v[i].second);
    int sum=0;
    for(int i=0;i<me.size();++i){
        int idx=bs(me[i],v);
        if(~idx)
        sum+=mx[idx];
    } 
    return sum;
    }
};