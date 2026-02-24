class Solution {
public:
    int inOrder(TreeNode* root,int s){
        if (root==NULL) return 0;

        s = (s << 1)|root->val; // binary->decimal

        if (root->left == NULL && root->right == NULL) return s;

        return inOrder(root->left, s) +  inOrder(root->right, s);
    }

    int sumRootToLeaf(TreeNode* root) {
        return inOrder(root, 0);
    }
};