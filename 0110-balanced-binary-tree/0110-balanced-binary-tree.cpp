class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        int Lheight = height(root->left);
        int Rheight = height(root->right);

        if(abs(Lheight-Rheight)>1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};