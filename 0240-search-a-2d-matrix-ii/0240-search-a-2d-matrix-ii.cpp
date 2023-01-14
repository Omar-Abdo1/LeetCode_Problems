class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int k) {
     
        
        for(int i=0;i<v.size();++i){
            int l=0,r=v[0].size()-1,mid;
            while(l<=r){
                mid=(l+r)/2;
                if(v[i][mid]==k)return 1;
             v[i][mid] > k ? r=mid-1 : l=mid+1;  
            }
        }
        return 0;
    }
};