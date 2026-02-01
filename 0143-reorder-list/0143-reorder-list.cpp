class Solution {
public:
    void reorderList(ListNode* head) {

        // 1. Find the Middle LL
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. reverse the linked LL
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* next;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. merge the LL
        ListNode* first = head;
        ListNode* second = prev;
        ListNode* temp;
        while(second->next!=NULL){
            temp = first->next;
            first->next = second;
            first = temp;

            temp = second->next;
            second->next = first;
            second = temp;
        }
    }
};