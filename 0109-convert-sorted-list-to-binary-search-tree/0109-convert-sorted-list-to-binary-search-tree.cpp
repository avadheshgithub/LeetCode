class Solution {
public:
    ListNode* curr;

    TreeNode* BST(int st, int end) {
        if(st>end) return NULL;

        int mid = st + (end-st)/2; // [inOrder --> L Root R]

        TreeNode* left = BST(st,mid-1); // Left

        TreeNode* root = new TreeNode(curr->val); //Root
        curr = curr->next;

        root->left = left;
        root->right = BST(mid+1,end); // Right

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        curr = head;

        ListNode* temp = head;
        while(temp!=NULL){
            n++;
            temp = temp->next;
        }

        return BST(0,n-1);
    }
};
