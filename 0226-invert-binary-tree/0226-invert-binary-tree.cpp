class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
         if(root==NULL) return NULL; 

        TreeNode* temp  = root->left;
        root->left = root->right;  // swapping 
        root->right = temp;

        invertTree(root->left); // repeat for each node
       invertTree(root->right);

        return root;
    }
};