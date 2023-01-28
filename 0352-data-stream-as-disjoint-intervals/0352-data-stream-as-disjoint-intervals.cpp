class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    void addNum(int x) {
        st.insert(x);
    }
    
    vector<vector<int>> getIntervals() {
    vector<vector<int>>ans;
        int s=-1,ed=-1;
        for(auto &me : st){
            if(s==-1){
                s=me;
                ed=me;
            }
            else if(me==ed+1){
                ed=me;
            }
            else{
                ans.push_back({s,ed});
                s=ed=me;
            }
        }
        if(ed!=-1)ans.push_back({s,ed});
        return ans;
    }
    private :
    set<int>st;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */