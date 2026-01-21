class Solution {
public:
    void inOrder(TreeNode* root,vector<int>&ans){
        if(root==NULL) return ;

        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        inOrder(root,ans);
        return ans[k-1];
    }
};