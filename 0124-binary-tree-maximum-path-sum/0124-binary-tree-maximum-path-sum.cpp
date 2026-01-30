class Solution {
public:
    int maxSum = INT_MIN;

    int PathSum(TreeNode* root){
        if(root==NULL) return 0;

        int LGain = max(PathSum(root->left),0);
        int RGain = max(PathSum(root->right),0);

        maxSum = max(maxSum,root->val+LGain+RGain);

        return root->val + max(LGain,RGain);
    }

    int maxPathSum(TreeNode* root) {
        PathSum(root);
        return maxSum;
    }
};
