class Solution {
public:
    void inOrder(TreeNode* root,vector<int>&ans){
        if(root==NULL) return;

        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }

    int minDiffInBST(TreeNode* root) {
        vector<int>ans;
        inOrder(root,ans);

        int dif = INT_MAX;
        for(int i=1;i<ans.size();i++){
            dif = min(dif,ans[i]-ans[i-1]);
        }
        return dif;
    }
};