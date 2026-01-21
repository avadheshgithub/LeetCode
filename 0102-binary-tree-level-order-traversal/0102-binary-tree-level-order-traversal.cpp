class Solution {
public:
    vector<vector<int>>ans;

    void order(TreeNode* root, int level){
        if(root == NULL) return;

        if(ans.size() == level) {
            ans.push_back(vector<int>());
        }
        
        ans[level].push_back(root->val);

        order(root->left, level + 1);
        order(root->right, level + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return ans;
        order(root,0);
        return ans;
    }
};