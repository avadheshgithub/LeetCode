class Solution {
public:
    TreeNode* findMin(TreeNode* root){
        while(root->left!=NULL){
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;

        if (key<root->val)     root->left = deleteNode(root->left,key);
        else if(key>root->val) root->right = deleteNode(root->right,key);

        else{                      
            if(root->left==NULL){  // 1 Child
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right==NULL){ // 1 child
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else{  // 2 child
                TreeNode* temp = findMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right,temp->val);
            }
        }
        return root; 
    }
};