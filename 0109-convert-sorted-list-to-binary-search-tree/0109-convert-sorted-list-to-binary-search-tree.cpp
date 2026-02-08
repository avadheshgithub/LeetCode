class Solution {
public:
    TreeNode* BST(vector<int>& nums, int st, int end) {
        if (st > end) return NULL;

        int mid = st + (end - st) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = BST(nums, st, mid - 1);
        root->right = BST(nums, mid + 1, end);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;

        while (head != NULL) {         // linked List to Arr
            nums.push_back(head->val);
            head = head->next;
        }
        return BST(nums, 0, nums.size() - 1);
    }
};
