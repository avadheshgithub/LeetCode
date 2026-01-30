class Solution {
public:

    int sum(TreeNode* root,int s){
        if(root==NULL) return 0;

        s = s * 10 + root->val;

        if(root->left==NULL && root->right==NULL)
            return s;

        return sum(root->left,s)+sum(root->right,s);
    }

    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        return sum(root,0);
    }
};