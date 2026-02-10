class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        
      ListNode* odd = head;
      ListNode* even = head->next;
      ListNode* temp = even;

      while(even && even->next){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
      }

      odd->next = temp;
      return head;
    }
};