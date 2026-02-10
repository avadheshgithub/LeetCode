
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto x:lists){
            while(x!=NULL){
                pq.push(x->val);
                x = x->next;
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(!pq.empty()){
          temp->next = new ListNode(pq.top());
          pq.pop();
          temp = temp->next;   
        }
        return dummy->next;
    }
};