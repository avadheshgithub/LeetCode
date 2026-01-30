class Solution {
public:
    bool Helper(TreeNode* root,int tar){
        if(root==NULL) return false;

        if(root->left==NULL && root->right==NULL){
            return root->val==tar;
        }

        return Helper(root->left,tar-root->val) || Helper(root->right,tar-root->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
       
        return Helper(root,targetSum);
    }
};