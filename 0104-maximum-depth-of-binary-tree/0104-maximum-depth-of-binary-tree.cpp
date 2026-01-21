class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        else{
            int Lmax = maxDepth(root->left);
            int Rmax = maxDepth(root->right);
            return max(Lmax,Rmax)+1;
        }
    }
};