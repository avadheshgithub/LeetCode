class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head==NULL or head->next==NULL) return head;
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = reverse(slow);
        ListNode* p = head;
        ListNode* q = temp;
        while(q!=NULL){
            if(p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};