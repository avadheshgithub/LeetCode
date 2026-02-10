
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL or head->next==NULL) return head;

        ListNode* curr = head;
        for(int i=0;i<k;i++){
            if(curr==NULL) return head;
            curr = curr->next;
        }

        int count = 0;
        curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(count<k){
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;

            count++;
        }

        head->next = reverseKGroup(curr,k);
        return prev;
    }
};