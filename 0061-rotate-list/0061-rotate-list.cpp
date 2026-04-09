class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next==NULL or k==0) return head;

        int n=1;
        ListNode* tail=head;

        while(tail->next!=NULL){
            n++;
            tail = tail->next;
        }
        if(k%n==0) return head;
        if(k>n) k = k%n;
        tail->next = head;

        ListNode* temp = head;
        for(int i=1;i<n-k;i++){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};