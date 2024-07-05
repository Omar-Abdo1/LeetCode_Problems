/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>v;
        while(head!=nullptr){
            v.push_back(head->val);
            head= head->next;
        }
        vector<int>idx;
        for(int i=1;i<v.size()-1;++i){
             if(v[i]>v[i-1] && v[i]>v[i+1])
                 idx.push_back(i);
            if(v[i]<v[i-1] && v[i]<v[i+1])
                idx.push_back(i);
        }
        if(idx.size()<2)return {-1,-1};
        vector<int>ans(2,1e9);
        ans[1] =  idx.back()-idx[0];
        for(int i=0;i+1<idx.size();++i)
            ans[0]=min(ans[0],idx[i+1]-idx[i]);
        return ans;
        
    }
};