class Solution {
public:
    void inOrder(TreeNode* root,vector<int>&ans){
        if(root==NULL) return;
        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }

    TreeNode* BST(int st,int end,vector<int>&nums){
        if(st>end) return NULL;

        int mid = st + (end-st)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = BST(st,mid-1,nums);
        root->right = BST(mid+1,end,nums);

        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL) return NULL;
        vector<int>ans;
        inOrder(root,ans);

        return BST(0,ans.size()-1,ans);
    }
};