class Solution {
public:
    int good(TreeNode* root, int max){
        if(root==NULL) return 0;
        int count = 0;

        if(root->val >= max){
            count=1;
            max = root->val;
        }
        count += good(root->left,max);
        count += good(root->right,max);

        return count;
    }
    int goodNodes(TreeNode* root) {
        return good(root,INT_MIN);
    }
};