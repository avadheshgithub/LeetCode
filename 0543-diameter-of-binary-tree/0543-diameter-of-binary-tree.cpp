
class Solution {
public:
    int diam = 0;

   int height(TreeNode* root){
        if(root==nullptr) return 0;

        int Lht = height(root->left);
        int Rht = height(root->right);

        diam = max(diam,Lht+Rht); // max dia

        return 1 + max(Lht,Rht); // height
    }

   int diameterOfBinaryTree(TreeNode* root) {
       height(root);
       return diam;
    }
};