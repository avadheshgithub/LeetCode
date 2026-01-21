class Solution {
public:
    bool isMirr(TreeNode *p,TreeNode *q){
        if(p==NULL and q==NULL) return true;
        if(p==NULL or q==NULL) return false;
        return (p->val==q->val && isMirr(p->left,q->right) && isMirr(p->right,q->left));
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isMirr(root->left,root->right);
    }
};