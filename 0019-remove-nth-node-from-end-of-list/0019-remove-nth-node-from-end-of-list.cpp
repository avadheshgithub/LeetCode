class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* F = dummy;
        ListNode* B = dummy;

        for(int i=0;i<=k;i++){
            F = F->next;
        }

        while(F!=NULL){
            F = F->next;
            B = B->next;
        }

        B->next = B->next->next;

        return dummy->next;
    }
};
