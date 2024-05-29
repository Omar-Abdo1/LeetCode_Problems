class Solution {
public:
    int numSteps(string s) {
        deque<char>dq;
            
        for(auto &i : s)
            dq.push_back(i);
        
        function<void()>add=[&](){
                    bool ok = 0;
                for(int i=dq.size()-1;i>=0;--i)
                    if(dq[i]=='0'){
                        dq[i]='1';
                        dq.back()='0';
                        ok = 1;
                        break;
                    }
            
            if(!ok){
                for(auto &i:dq)i='0';
            dq.push_front('1');
            }
        };
         int steps =  0;
        while(dq.size()!=1){
            if(dq.back()=='1')add();
            else dq.pop_back();
            ++steps;
        }
        return steps;
    }
};
/*

*/