class Solution {
public:
    void inOrd (TreeNode* root,vector<int>& ans){
        if(root==NULL) return;

        inOrd(root->left,ans); // L
        ans.push_back(root->val); //root
        inOrd(root->right,ans); // R
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inOrd(root,ans);
        return ans;
    }
};