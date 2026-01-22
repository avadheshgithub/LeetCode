class Solution {
public:
    int sum = 0;
    TreeNode* revInOrder(TreeNode* root){
        if(root==NULL) return 0;

        revInOrder(root->right);
        root->val += sum;
        sum = root->val;
        revInOrder(root->left);

        return root;
    }

    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return NULL;
        return revInOrder(root);
    }
};