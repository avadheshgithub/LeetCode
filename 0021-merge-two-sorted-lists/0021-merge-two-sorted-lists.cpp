class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
       if(a==NULL or b==NULL){
        return a==NULL ? b : a;
       } 
       ListNode* dummy = new ListNode(-1);
       ListNode* temp = dummy;

       while(a!=NULL and b!=NULL){
            if(a->val <= b->val){
                temp->next = a;
                a = a->next;
            }
            else{
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }
        if(b==NULL){
            temp->next = a;
        }
        else temp->next = b;

       return dummy->next;
    }
};