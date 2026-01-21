class Solution {
public:
    void postOrder(TreeNode* root,vector<int>& ans){ 
        if(root==NULL) return;

        postOrder(root->left,ans); // L
        postOrder(root->right,ans); // R
        ans.push_back(root->val); //root
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postOrder(root,ans);
        return ans;
    }
};