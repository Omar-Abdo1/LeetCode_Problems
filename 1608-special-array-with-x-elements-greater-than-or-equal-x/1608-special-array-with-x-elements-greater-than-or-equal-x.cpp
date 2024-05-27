class Solution {
public:
    int specialArray(vector<int>&v) {
       
        for(int x=1;x<=v.size();++x){
          int cnt = 0;
          for(auto &i : v)
              cnt+= i>=x;
        if(cnt==x)
            return x;
       }
    return -1;
        
    }
};