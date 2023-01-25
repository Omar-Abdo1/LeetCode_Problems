class Solution {
public:
    int nthUglyNumber(int n) {  
    set<long long>st;
    st.insert(1);
    while(--n){
    auto cur =*st.begin();
     st.erase(cur);
      st.insert(2*cur);
      st.insert(3*cur);
      st.insert(5*cur);
    }
    return *st.begin(); 
        
        
        
    }
};