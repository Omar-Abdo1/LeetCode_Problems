class Solution {
public:
    int longestValidParentheses(string s) {
      int n=s.size();
      vector<int>v(n);
        stack<int>st;
        for(int i=0;i<n;++i){
         
            if(s[i]=='('){
                st.push(i);
            }
            else{
              
                if(st.size()){
                    v[i]=1;
                    v[st.top()]=1;
                    st.pop();
                }
            }
        }
        int mx=0;
        int c=0;
        for(auto i : v){
            if(i)c++;
            else mx=max(mx,c),c=0;
        }
        return max(mx,c);
        
        
        
    }
};