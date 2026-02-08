class Solution {
public:
    TreeNode* BST(vector<int>&nums,int st, int end){
        if(st>end) return NULL;

        int mid = st + (end-st)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = BST(nums,st,mid-1);
        root->right = BST(nums,mid+1,end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums,0,nums.size()-1);
    }
};