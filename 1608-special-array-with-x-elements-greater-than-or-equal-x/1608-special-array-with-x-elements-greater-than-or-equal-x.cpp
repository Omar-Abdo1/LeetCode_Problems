class Solution {
public:
    int specialArray(vector<int>&v) {
       
        int n = v.size();
        
        vector<int> freq(n+1);
        for(auto &i : v)
            freq[min(n,i)]++;
       int Greater = 0;
        for(int i=n;i>=0;--i){
            Greater += freq[i];
            if(Greater == i)
                return i;
        }
        return -1;
        
    }
};