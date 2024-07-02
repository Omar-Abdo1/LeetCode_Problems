class Solution {
public:
    vector<int> intersect(vector<int>& v1, vector<int>& v2) {
        unordered_map<int,int>f1,f2;
        for(auto &i : v1)++f1[i];
        for(auto &i : v2)++f2[i];
        vector<int>ans;
        for(auto &[x,y] : f1){
            if(f2[x]){
                int q = min(f2[x],y);
                while(q--)
                ans.push_back(x);
            }
        }
            return ans;
    }
};