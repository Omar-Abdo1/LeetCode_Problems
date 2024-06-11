class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a, vector<int>& arr2) {
        unordered_map<int,int>mp;
        int id = 0;
        for(auto &i : arr2)mp[i]=id++;
        for(auto &i : a)
            if(mp.count(i)==0)mp[i]=i+id;
        sort(a.begin(),a.end(),[&](int x,int y){return mp[x]<=mp[y];});
        return a;
    }
};