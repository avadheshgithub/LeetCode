class Solution {
public:
    void preOrder(TreeNode* root,vector<int>& ans){ 
        if(root==NULL) return;

        ans.push_back(root->val); //root
        preOrder(root->left,ans); // L
        preOrder(root->right,ans); // R
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preOrder(root,ans);
        return ans;
    }
};