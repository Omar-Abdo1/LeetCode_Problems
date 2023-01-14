class Solution {
public:
    vector<int>par;
    int findleader(int i){
        if(i==par[i])return i;
        return par[i]=findleader(par[i]);
    }
    void add(int i,int j){
        int a=findleader(i);
        int b=findleader(j);
        if(a==b)return ;
        if(a>b)swap(a,b);
        par[b]=a;
    }
    string smallestEquivalentString(string s1, string s2, string k) {
       par=vector<int>(26);
        iota(par.begin(),par.end(),0);
        for(int i=0;i<s1.size();++i)add(s1[i]-'a',s2[i]-'a');
        for(auto &i:k)i=(char)findleader(i-'a')+'a';
        return k;
    }
};