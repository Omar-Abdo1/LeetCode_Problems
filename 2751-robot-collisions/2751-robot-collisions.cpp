struct robot{
    int pos,health,idx;
    char dir;
    bool operator<(const robot &other)const{
        return pos<other.pos;
    }
};
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<robot>robots;
        for(int i=0;i<positions.size();++i)
            robots.push_back({ positions[i],healths[i],i,directions[i] });
        sort(robots.begin(),robots.end());
        stack<int>st;
        set<int>stt;
        for(int i=0;i<positions.size();++i)stt.insert(i);
        vector<int>ans;
        for(int i=0;i<robots.size();++i){
            if(robots[i].dir=='R')
                st.push(robots[i].idx);
            else{
                if(st.size()){
                    if( healths[st.top()]>healths[ robots[i].idx ]){
                        stt.erase(robots[i].idx);
                        healths[st.top()]--;
                    }
                    else if( healths[ robots[i].idx ]>healths[st.top()] ){
                        while(st.size() &&  healths[ robots[i].idx ]>healths[st.top()] ){
                            stt.erase(st.top());
                            healths[robots[i].idx]--;
                            st.pop();
                        }
                        if(st.size()){
                            if(healths[st.top()]> healths[ robots[i].idx ]){
                        stt.erase(robots[i].idx);
                        healths[st.top()]--;
                    }
                            else{
                             stt.erase(robots[i].idx);
                        stt.erase(st.top());
                        st.pop();   
                            }
                        
                        }
                        
                    }
                    else{
                        stt.erase(robots[i].idx);
                        stt.erase(st.top());
                        st.pop();
                    }
                }
            }
        }
        
        for(int i=0;i<positions.size();++i)
            if(stt.count(i))
                ans.push_back(healths[i]);
        return ans;
        
    }
};