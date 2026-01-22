
class Solution {
public:
    int maxSum = INT_MIN;

    int maxGain(TreeNode* root){
        if(root==NULL) return 0;

        int leftGain = max(maxGain(root->left),0);
        int rightGain = max(maxGain(root->right),0);

        maxSum = max(maxSum, root->val + leftGain + rightGain);

        return root->val + max(leftGain,rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};