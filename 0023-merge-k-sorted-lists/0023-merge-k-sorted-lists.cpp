
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> PQ;
        for(ListNode* list:lists){
            while(list!=NULL){
                PQ.push(list->val);
                list = list->next;
            }
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* merge=dummy;

        while(!PQ.empty()){
            merge->next = new ListNode(PQ.top());
            PQ.pop();
            merge = merge->next;
        }
        return dummy->next;
    }
};